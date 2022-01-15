#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    Node* left;
    Node* right;
};

typedef struct Tree {
    Node* root;
};

Node* makeNode(Node *left, int data, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = data;
    node->left = left;
    node->right = right;
    return node;
}

void preOrder(Node* root) {
    if(root==NULL) return;
    cout << root->value << " ";
    inOrder(root->left);
    inOrder(root->right);
}

void inOrder(Node* root) {
    if(root==NULL) return;
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(root==NULL) return;
    inOrder(root->left);
    inOrder(root->right);
    cout << root->value << " ";
}

int main() {
    Tree tree;
    Node* n4 = makeNode(NULL, 4, NULL);
    Node* n5 = makeNode(NULL, 5, NULL);
    Node* n2 = makeNode(n4, 2, n5);
    Node* n3 = makeNode(NULL, 3, NULL);
    Node* n1 = makeNode(n2, 1, n3);
    tree.root = n1;
    inOrder(tree.root);
}