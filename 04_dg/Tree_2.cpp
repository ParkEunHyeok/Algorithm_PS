#include <iostream>
#define MAX_SIZE 10
using namespace std;

typedef struct Node {
    int data;
};

typedef struct Tree {
    int nodeCount;
    bool matrix[MAX_SIZE][MAX_SIZE];
    Node nodes[MAX_SIZE];
};

Tree tree;

void initTree() {
    tree.nodeCount = MAX_SIZE;
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            tree.matrix[i][j] = 0;
        }
        tree.nodes[i].data = i;
    }
}

void printTreeMatrix() {
    int nodeCount = tree.nodeCount;
    cout << "Tree Matrix\n";

    for(int i=0; i<nodeCount; i++) {
        for(int j=0; j<nodeCount; j++) {
            cout << tree.matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void addEdge(int parentNodeIndex, int childNodeIndex) {
    tree.matrix[parentNodeIndex][childNodeIndex] = true;
}

void dfs(int nodeIndex) {
    for(int i=0; i<tree.nodeCount; i++) {
        if(tree.matrix[nodeIndex][i]==true) {
            dfs(i);
        }
    }
    cout << tree.nodes[nodeIndex].data << " ";
}

int main() {
    initTree();
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,5);
    addEdge(2,6);

    printTreeMatrix();
    dfs(0);
    return 0;
}