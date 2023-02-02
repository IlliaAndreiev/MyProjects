#include <iostream>
#include <cassert>
using namespace std;

typedef int dataType;

struct node {
    dataType data;  
    node* left; 
    node* right; 
};


node* createNode(dataType data, node* left, node* right) {
    node* v = new node;
    v->data = data;
    v->left = left;
    v->right = right;
    return v;
}


node* readTree() {
    dataType data;
    char left, right;
    cin >> data >> left >> right;
    node* root = createNode(data, NULL, NULL);
    assert(left == 'Y' || left == 'N');
    assert(right == 'Y' || right == 'N');
    if (left == 'Y') {
        root->left = readTree();
    }
    if (right == 'Y') {
        root->right = readTree();
    }
    return root;
}


void destroyTree(node* v) {
    if (v != NULL) {
        destroyTree(v->left);
        destroyTree(v->right);
        delete v;
    }
}


int treeCount(node* root) {
    int countLeft = 0;
    int countRight = 0;
    if (root->left != NULL) {
        countLeft = treeCount(root->left);
    }
    if (root->right != NULL) {
        countRight = treeCount(root->right);
    }
    return countLeft + countRight + 1;
}

void display(node* root)
{
    if (root != NULL)
    {       
        display(root->left);
        display(root->right);
        cout << root->data << " " << treeCount(root) << endl;
    }
}


int main(void) {
    node* root = readTree();

    // TODO
    display(root);

    destroyTree(root);
}