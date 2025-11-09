#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    int h;
};

int height(Node* n) {
    return n ? n->h : 0;
}

int getBal(Node* n) {
    return n ? height(n->l) - height(n->r) : 0;
}

Node* newNode(int v) {
    Node* n = new Node;
    n->val = v;
    n->l = n->r = NULL;
    n->h = 1;
    return n;
}

Node* rightRotate(Node* y) {
    Node* x = y->l;
    Node* t2 = x->r;
    x->r = y;
    y->l = t2;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->r;
    Node* t2 = y->l;
    y->l = x;
    x->r = t2;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}

Node* balance(Node* root) {
    root->h = max(height(root->l), height(root->r)) + 1;
    int b = getBal(root);
    if (b > 1 && getBal(root->l) >= 0) return rightRotate(root);
    if (b < -1 && getBal(root->r) <= 0) return leftRotate(root);
    if (b > 1 && getBal(root->l) < 0) {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }
    if (b < -1 && getBal(root->r) > 0) {
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }
    return root;
}

Node* convertToAVL(Node* root) {
    if (!root) return NULL;
    root->l = convertToAVL(root->l);
    root->r = convertToAVL(root->r);
    return balance(root);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->l);
    cout << root->val << " ";
    inorder(root->r);
}

int main() {
    Node* root = newNode(30);
    root->l = newNode(20);
    root->r = newNode(40);
    root->l->l = newNode(10);

    root = convertToAVL(root);

    inorder(root);
    return 0;
}
