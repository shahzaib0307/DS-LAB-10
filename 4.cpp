// Question#4: Search for the value defined by the user in the tree. If the value does not
// exist insert it and print the new tree.

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
    else if (v > root->val) root->r = insert(root->r, v);
    return root;
}

bool search(Node* root, int v) {
    if (!root) return false;
    if (root->val == v) return true;
    if (v < root->val) return search(root->l, v);
    else return search(root->r, v);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->l);
    cout << root->val << " ";
    inorder(root->r);
}

int main() {
    Node* root = NULL;
    int n, v;
    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "ENTER VALUE #" << i + 1 << ": ";
        cin >> x;
        root = insert(root, x);
    }
    cout << "ENTER VALUE TO SEARCH: ";
    cin >> v;
    if (search(root, v)) cout << "VALUE FOUND IN TREE\n";
    else {
        cout << "VALUE NOT FOUND, INSERTING...\n";
        root = insert(root, v);
    }
    cout << "UPDATED TREE (INORDER): ";
    inorder(root);
    cout << endl;
}
