#include <iostream>
using namespace std;
#define NODE_SIZE 9

int getParent(int node, int parent[]) {
    if(node==parent[node]) return node;
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

int main() {
    // 부모 노드 생성
    int parent[NODE_SIZE] = {0,};

    // 초기화
    for(int i=0; i<NODE_SIZE; i++) {
        parent[i] = i;
    }

    unionParent(1, 2, parent);
    unionParent(2, 3, parent);
    unionParent(3, 4, parent);

    unionParent(5, 6, parent);
    unionParent(6, 7, parent);
    unionParent(7, 8, parent);

    cout << "1과 8 연결 여부 : " << findParent(1, 8, parent) << endl;
    cout << "1과 4 연결 여부 : " << findParent(1, 4, parent) << endl;
    cout << endl << "1과 8 UnionParent 실행" << "\n\n";

    return 0;
}