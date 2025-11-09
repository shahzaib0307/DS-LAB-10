#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
};

Node* makeNode(int v) {
    Node* n = new Node;
    n->val = v;
    n->l = n->r = NULL;
    return n;
}

Node* insert(Node* root, int v) {
    if (!root) return makeNode(v);
    if (v < root->val) root->l = insert(root->l, v);
    else root->r = insert(root->r, v);
    return root;
}

bool isBSTUtil(Node* root, int min, int max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return isBSTUtil(root->l, min, root->val) && isBSTUtil(root->r, root->val, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -10000, 10000);
}

int main() {
    Node* root = NULL;
    int arr[5] = {10, 5, 20, 25, 30};
    for (int i = 0; i < 5; i++) root = insert(root, arr[i]);
    if (isBST(root)) cout << "TREE IS A BST\n";
    else cout << "TREE IS NOT A BST\n";
}
