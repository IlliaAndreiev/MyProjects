#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

typedef int dataType;


struct node {
    int data;      
    node* parent; 
    node* left;    
    node* right;   
};


struct set {
    node* root; 
};


void init(set& s) {
    s.root = NULL;
}



void destroy(node* root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}



void destroy(set& s) {
    destroy(s.root);
}




node* buildSubtree(int left, int right, int a[], node* parent) {
    // TODO 
    if (left > right) return NULL;
    parent = new node;
    parent->parent = NULL;
    parent->data = a[(left+right)/2];
    parent->right = buildSubtree(((left + right) / 2) + 1, right, a, parent->right);
    if(parent->right != NULL) parent->right->parent = parent;
    parent->left = buildSubtree(left, ((left + right) / 2) - 1, a, parent->left);
    if (parent->left != NULL) parent->left->parent = parent;
    return parent;
}



void buildTree(set& s, int n, int a[]) {
    assert(s.root == NULL);
    s.root = buildSubtree(0, n - 1, a, NULL);
}



void printData(node* v) {
    if (v == NULL) {
        cout << "NULL";
    }
    else {
        cout << v->data;
    }
}




void inorder(node* root) {
    if (root != NULL) {
        // vypiseme lavy podstrom
        inorder(root->left);

        cout << "data: " << root->data;
        cout << ", parent: ";
        printData(root->parent);
        cout << ", left: ";
        printData(root->left);
        cout << ", right: ";
        printData(root->right);
        cout << endl;

        inorder(root->right);
    }
}


void printInorder(set& s) {
    inorder(s.root);
}

int main(void) {
    const int MAXN = 1000;


    int n;
    cin >> n;
    int a[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        assert(i == 0 || a[i - 1] < a[i]);
    }


    set tree;
    init(tree);

    buildTree(tree, n, a);

    printInorder(tree);

    destroy(tree);
}