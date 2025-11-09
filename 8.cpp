// Given a Binary Search Tree (BST) and a range [a, b], the task is to count the number of
// nodes in the BST that lie in the given range.
// Examples:
// Input: a= 5, b = 45

// Output: 3
// Explanation: There are three nodes in range [5, 45] = 5, 10 and 40.

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

int countRange(Node* root, int a, int b) {
    if (!root) return 0;
    if (root->val < a) return countRange(root->r, a, b);
    if (root->val > b) return countRange(root->l, a, b);
    return 1 + countRange(root->l, a, b) + countRange(root->r, a, b);
}

int main() {
    Node* root = NULL;
    int n, x, a, b;
    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "ENTER VALUE #" << i + 1 << ": ";
        cin >> x;
        root = insert(root, x);
    }
    cout << "ENTER RANGE (a b): ";
    cin >> a >> b;
    int cnt = countRange(root, a, b);
    cout << "NODES IN RANGE [" << a << ", " << b << "]: " << cnt << endl;
}
