#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define NODE_SIZE 9

int getParent(int node, int parent[]) {
    if(node==parent[node]) return parent[node];
    return parent[node] = getParent(parent[node], parent);
}

void unionParent(int first, int second, int parent[]) {
    int firstParent = getParent(first, parent);
    int secondParent = getParent(second, parent);

    if(firstParent < secondParent)
        parent[secondParent] = firstParent;
    else
        parent[firstParent] = secondParent;
}

bool findParent(int first, int second, int parent[]) {
    if(getParent(first, parent)==getParent(second, parent))
        return true;
    return false;
}

int n, m;
struct Edge {
public:
    int firstNode;
    int secondNode;
    int weight;
};

int compare(Edge *first, Edge *second) {
    return first->weight < second->weight;
}

/* 입력값
7 11
1 7 12
1 4 28
1 2 67
1 5 17
2 4 24
2 5 62
3 5 20
3 6 37
4 7 13
5 6 45
5 7 73
답:123 */

int main() {
    vector<Edge *> edges;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        Edge* edge = new Edge();
        cin >> edge->firstNode >> edge->secondNode >> edge->weight;
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), compare);

    // parnet 배열 생성
    int* parent = (int *) malloc(sizeof(int) * (n+1));
    // 초기화
    for(int i=0; i<=n; i++) parent[i] = i;

    vector<Edge *> result;

    for(int i=0; i<edges.size(); i++) {
        Edge *edge = edges.at(i);

        int firstParent = getParent(edge->firstNode, parent);
        int secondParent = getParent(edge->secondNode, parent);

        if(firstParent != secondParent) {
            unionParent(edge->firstNode, edge->secondNode, parent);
            result.push_back(edge);
        }
    }

    int totalWeight = 0;
    for(int i=0; i<result.size(); i++) {
        Edge* e = result.at(i);
        cout << "first : " << e->firstNode;
        cout << ", second : " << e->secondNode;
        cout << ", weight : " << e->weight << endl;
        totalWeight += e->weight;
    }

    cout << "totalWeight : " << totalWeight << endl;
    return 0;
}