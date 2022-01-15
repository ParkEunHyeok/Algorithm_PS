#include <iostream>
#include <vector>
#define MAX_NODE_COUNT 10
using namespace std;

typedef struct Node {
    int data;
};

typedef struct Tree {
    int nodeCount;
    Node nodes[MAX_NODE_COUNT];
};

vector<int> adj[MAX_NODE_COUNT];
Tree tree;

void initTree() {
    tree.nodeCount = MAX_NODE_COUNT;
    for(int i=0; i<MAX_NODE_COUNT; i++) {
        tree.nodes[i].data = i;
    }
}

void printTreeMatrix() {
    int nodeCount = tree.nodeCount;
    cout << "Tree adj\n";

    for(int i=0; i<nodeCount; i++) {
        cout << i << " -> ";
        for(int j=0; j<adj[i].size(); j++) {
            cout << adj[i][j] << " -> ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void addEdge(int parentNodeIndex, int childNodeIndex) {
    adj[parentNodeIndex].push_back(childNodeIndex);
}

void dfs(int nodeIndex) {
    for(int i=0; i<adj[nodeIndex].size(); i++) {
        dfs(adj[nodeIndex][i]);
    }
    cout << tree.nodes[nodeIndex].data << " ";
}

int main() {
    initTree();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);

    printTreeMatrix();
    dfs(0);
    return 0;
}