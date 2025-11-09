// Question#6: Suppose you are working on a project for a small online retailer that needs
// to keep track of their inventory using a binary search tree. The retailer’s inventory
// consists of a unique product ID and its corresponding quantity in stock. Write a C++
// class for the binary search tree and add the required functionalities to insert new
// products into the tree, update the quantity of existing products, and search for products
// by their ID.
// Additionally, the retailer would like to keep track of the product with the highest quantity
// in
// stock. Implement a function that returns the ID of this product, along with its quantity.

#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int qty;
    Node* l;
    Node* r;
    Node(int i, int q) {
        id = i;
        qty = q;
        l = r = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }
    Node* insert(Node* n, int id, int qty) {
        if (!n) return new Node(id, qty);
        if (id < n->id) n->l = insert(n->l, id, qty);
        else if (id > n->id) n->r = insert(n->r, id, qty);
        else n->qty = qty;
        return n;
    }
    void insert(int id, int qty) {
        root = insert(root, id, qty);
    }
    Node* search(Node* n, int id) {
        if (!n) return NULL;
        if (n->id == id) return n;
        if (id < n->id) return search(n->l, id);
        else return search(n->r, id);
    }
    void search(int id) {
        Node* f = search(root, id);
        if (f) cout << "FOUND PRODUCT ID: " << f->id << " QTY: " << f->qty << endl;
        else cout << "NOT FOUND\n";
    }
    void inorder(Node* n) {
        if (!n) return;
        inorder(n->l);
        cout << "ID: " << n->id << " QTY: " << n->qty << endl;
        inorder(n->r);
    }
    void show() {
        inorder(root);
    }
    void update(int id, int qty) {
        Node* f = search(root, id);
        if (f) f->qty = qty;
        else cout << "PRODUCT NOT FOUND\n";
    }
    void maxQty(Node* n, int& mid, int& mqty) {
        if (!n) return;
        if (n->qty > mqty) {
            mqty = n->qty;
            mid = n->id;
        }
        maxQty(n->l, mid, mqty);
        maxQty(n->r, mid, mqty);
    }
    void maxProduct() {
        int mid = -1, mqty = -1;
        maxQty(root, mid, mqty);
        if (mid == -1) cout << "NO PRODUCTS\n";
        else cout << "MAX QTY PRODUCT ID: " << mid << " QTY: " << mqty << endl;
    }
};

int main() {
    BST t;
    int ch;
    while (1) {
        cout << "\n1. INSERT\n2. SEARCH\n3. UPDATE\n4. DISPLAY\n5. MAX PRODUCT\n6. EXIT\nCHOICE: ";
        cin >> ch;
        if (ch == 1) {
            int id, qty;
            cout << "ENTER ID AND QTY: ";
            cin >> id >> qty;
            t.insert(id, qty);
        } else if (ch == 2) {
            int id;
            cout << "ENTER ID: ";
            cin >> id;
            t.search(id);
        } else if (ch == 3) {
            int id, qty;
            cout << "ENTER ID AND NEW QTY: ";
            cin >> id >> qty;
            t.update(id, qty);
        } else if (ch == 4) {
            t.show();
        } else if (ch == 5) {
            t.maxProduct();
        } else break;
    }
}
