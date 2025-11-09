// Question#7: Given a Binary Search Tree, find the median of it.
//  If number of nodes are even: then median = ((n/2 + ((n)/2+1) ) /2
//  If number of nodes are odd: then median = (n+1)/2


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

void store(Node* root, int arr[], int& i) {
    if (!root) return;
    store(root->l, arr, i);
    arr[i++] = root->val;
    store(root->r, arr, i);
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->l) + countNodes(root->r);
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "ENTER VALUE #" << i + 1 << ": ";
        cin >> x;
        root = insert(root, x);
    }
    int cnt = countNodes(root);
    int* arr = new int[cnt];
    int idx = 0;
    store(root, arr, idx);
    if (cnt % 2 == 0) {
        int m1 = arr[cnt / 2 - 1];
        int m2 = arr[cnt / 2];
        cout << "MEDIAN: " << (m1 + m2) / 2.0 << endl;
    } else {
        cout << "MEDIAN: " << arr[cnt / 2] << endl;
    }
}
