// Question#3
// Create the BST which stores the students object in BST and student object has the
// property like name, roll and score. Create tree based on name of student AND Perform
// following operations in BST:
//  Insert the student record,
//  Search the students based on name
//  Delete the students whose score is less than 10
//  And get the students whose score is max in tree.
// In main function create the object array of students with 10 students from those store 7
// seven students randomly and perform all above objects.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student { string name; int roll; int score; };
struct Node { Student s; Node* left; Node* right; Node(const Student& st): s(st), left(nullptr), right(nullptr) {} };

Node* insertNode(Node* root, const Student& st) {
    if (!root) return new Node(st);
    if (st.name < root->s.name) root->left = insertNode(root->left, st);
    else if (st.name > root->s.name) root->right = insertNode(root->right, st);
    else root->s = st;
    return root;
}

Node* findMin(Node* n) {
    while (n && n->left) n = n->left;
    return n;
}

Node* removeByName(Node* root, const string& name) {
    if (!root) return nullptr;
    if (name < root->s.name) root->left = removeByName(root->left, name);
    else if (name > root->s.name) root->right = removeByName(root->right, name);
    else {
        if (!root->left) { Node* r = root->right; delete root; return r; }
        if (!root->right) { Node* l = root->left; delete root; return l; }
        Node* m = findMin(root->right);
        root->s = m->s;
        root->right = removeByName(root->right, m->s.name);
    }
    return root;
}

Node* removeIfScoreLessThan(Node* root, int thresh) {
    if (!root) return nullptr;
    root->left = removeIfScoreLessThan(root->left, thresh);
    root->right = removeIfScoreLessThan(root->right, thresh);
    if (root->s.score < thresh) {
        if (!root->left) { Node* r = root->right; delete root; return r; }
        if (!root->right) { Node* l = root->left; delete root; return l; }
        Node* m = findMin(root->right);
        root->s = m->s;
        root->right = removeByName(root->right, m->s.name);
    }
    return root;
}

Node* searchByName(Node* root, const string& name) {
    if (!root) return nullptr;
    if (name < root->s.name) return searchByName(root->left, name);
    if (name > root->s.name) return searchByName(root->right, name);
    return root;
}

Student* findMaxScore(Node* root) {
    if (!root) return nullptr;
    Student* best = &root->s;
    Student* l = findMaxScore(root->left);
    Student* r = findMaxScore(root->right);
    if (l && l->score > best->score) best = l;
    if (r && r->score > best->score) best = r;
    return best;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Student arr[10] = {
        {"Alice",1,12},{"Bob",2,9},{"Charlie",3,18},{"Diana",4,7},{"Evan",5,15},
        {"Fiona",6,22},{"George",7,5},{"Hannah",8,14},{"Ian",9,10},{"Jane",10,8}
    };
    srand((unsigned)time(0));
    int idx[10];
    for (int i=0;i<10;i++) idx[i]=i;
    for (int i=9;i>0;i--) {
        int j = rand()%(i+1);
        int t = idx[i]; idx[i]=idx[j]; idx[j]=t;
    }
    Node* root = nullptr;
    for (int i=0;i<7;i++) root = insertNode(root, arr[idx[i]]);
    Node* found = searchByName(root, arr[idx[2]].name);
    if (found) cout << "Found: " << found->s.name << " " << found->s.roll << " " << found->s.score << "\n";
    else cout << "Not found\n";
    root = removeIfScoreLessThan(root, 10);
    Student* mx = findMaxScore(root);
    if (mx) cout << "Max: " << mx->name << " " << mx->roll << " " << mx->score << "\n";
    else cout << "Tree empty\n";
    deleteTree(root);
    return 0;
}
