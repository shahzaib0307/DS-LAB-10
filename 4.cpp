
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    int size;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1), size(1) {}
};

int height(Node* n) { return n ? n->height : 0; }
int sizeOf(Node* n) { return n ? n->size : 0; }

void update(Node* n) {
    if (!n) return;
    n->height = 1 + max(height(n->left), height(n->right));
    n->size = 1 + sizeOf(n->left) + sizeOf(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}

int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    update(node);
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key >= node->right->key)
        return leftRotate(node);
    if (balance > 1 && key >= node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

pair<bool,int> kthSmallest(Node* root, int k) {
    if (!root || k <= 0 || k > sizeOf(root)) return {false, 0};
    int leftSize = sizeOf(root->left);
    if (k == leftSize + 1) return {true, root->key};
    if (k <= leftSize) return kthSmallest(root->left, k);
    return kthSmallest(root->right, k - leftSize - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        root = insert(root, x);
    }
    int k;
    cin >> k;

    int total = sizeOf(root);
    auto small = kthSmallest(root, k);
    auto large = kthSmallest(root, total - k + 1);

    if (small.first)
        cout << "Kth smallest: " << small.second << '\n';
    else
        cout << "Kth smallest: not found\n";

    if (large.first)
        cout << "Kth largest: " << large.second << '\n';
    else
        cout << "Kth largest: not found\n";

    cout << "Left height: " << height(root ? root->left : nullptr) << '\n';
    cout << "Right height: " << height(root ? root->right : nullptr) << '\n';

    return 0;
}
