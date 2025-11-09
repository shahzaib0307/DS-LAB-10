// Question#1:Question#1:
// Implement a binary search tree and perform all operations you learned above like:
// Inserting, Deleting, Searching, and Traversing.
// Implement a binary search tree and perform all operations you learned above like:
// Inserting, Deleting, Searching, and Traversing.

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* search(Node* root, int key) {
    if (!root || root->key == key)
        return root;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        }
        if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        }
        Node* succ = findMin(root->right);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }
    return root;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->key << " ";
    inorder(r->right);
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->key << " ";
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->key << " ";
}

int main() {
    Node* root = nullptr;
    int choice, x;
    while (true) {
        cout << "1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.Postorder 7.Exit\n";
        if (!(cin >> choice))
            break;
        if (choice == 1) {
            cin >> x;
            root = insert(root, x);
        } else if (choice == 2) {
            cin >> x;
            root = deleteNode(root, x);
        } else if (choice == 3) {
            cin >> x;
            cout << (search(root, x) ? "Found\n" : "Not found\n");
        } else if (choice == 4) {
            inorder(root);
            cout << "\n";
        } else if (choice == 5) {
            preorder(root);
            cout << "\n";
        } else if (choice == 6) {
            postorder(root);
            cout << "\n";
        } else {
            break;
        }
    }
    return 0;
}
