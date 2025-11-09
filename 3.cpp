

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* l;
    Node* r;
    int h;
    Node(int v) {
        val = v;
        l = r = NULL;
        h = 1;
    }
};

class AVLTree {
public:
    Node* root;
    AVLTree() { root = NULL; }

    int height(Node* n) {
        return n ? n->h : 0;
    }

    int getBal(Node* n) {
        return n ? height(n->l) - height(n->r) : 0;
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

    Node* insert(Node* root, int v) {
        if (!root) return new Node(v);
        if (v < root->val) root->l = insert(root->l, v);
        else if (v > root->val) root->r = insert(root->r, v);
        else return root;

        root->h = 1 + max(height(root->l), height(root->r));
        int b = getBal(root);

        if (b > 1 && v < root->l->val) return rightRotate(root);
        if (b < -1 && v > root->r->val) return leftRotate(root);
        if (b > 1 && v > root->l->val) {
            root->l = leftRotate(root->l);
            return rightRotate(root);
        }
        if (b < -1 && v < root->r->val) {
            root->r = rightRotate(root->r);
            return leftRotate(root);
        }
        return root;
    }

    void insert(int v) {
        root = insert(root, v);
    }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->l);
        cout << n->val << " ";
        inorder(n->r);
    }

    void show() {
        inorder(root);
        cout << endl;
    }

    void rotateRootLeft() {
        root = leftRotate(root);
    }
};

int main() {
    AVLTree t;
    int arr[7] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) t.insert(arr[i]);
    cout << "BEFORE INSERTION: ";
    t.show();
    t.insert(55);
    cout << "AFTER INSERTION OF 55: ";
    t.show();
    t.rotateRootLeft();
    cout << "AFTER LEFT ROTATION ON ROOT: ";
    t.show();
}
