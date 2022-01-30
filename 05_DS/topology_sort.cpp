#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX_NODE 8
using namespace std;

// 위상 정렬 계산 방법 :
// 1. 진입차수가 0인 정점을 큐에 삽입
// 2. 큐에서 원소를 꺼내 연결된 모든 간선 정보를 제거 (차수를 감소시킴)
// 3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입
// 4. 큐가 빌 때까지 2~3번 과정 반복
// -- 만일 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재하는 것이고,
//    모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과가 됨.

typedef struct Node {
    int data;   // 저장할 데이터
    vector<Node*> adj;  // 인접리스트
};

typedef struct Graph {
    vector<Node*> nodes;
};

int degree[MAX_NODE];   // 각각의 노드의 진입차수를 계산하여 저장할 배열
vector<Node*> result;   // 정렬된 결과를 저장할 배열

void makeNode(Graph *g, int count) {
    for(int i=0; i<count; i++) {
        Node* n = new Node();
        n->data = i;
        g->nodes.push_back(n);
    }
}

// 노드간의 엣지 생성(위상정렬은 방향 그래프여야함)
void addDirectedEdge(Graph *g, int n1, int n2) {
    Node* first = g->nodes.at(n1);
    Node* second = g->nodes.at(n2);

    first -> adj.push_back(second);
}

// 모든 노드의 진입차수 계산
void calcInDegree(Graph* g) {
    // 모든 노드의 진입 차수 계산을 위해 그래프의 모든 노드 탐색
    for(int i=1; i<g->nodes.size(); i++) {
        Node* n1 = g->nodes.at(i);  // i번째 노드 가져옴

        // i번째 노드의 모든 인접한 노드들을 확인해야함
        for(int j=0; j<n1->adj.size(); j++) {
            Node* adj = n1->adj.at(j);  // j번째 인접 노드

            // adj노드가 그래프의 노드 배열에 몇 번째 속해있는지 인덱스 찾기
            auto it = find(g->nodes.begin(), g->nodes.end(), adj);
            if(it != g->nodes.end()) {
                int index = it - g->nodes.begin();
                degree[index]++;    // 해당 노드의 진입차수 증가
            }
        }
    }
}

void topologySort(Graph* g) {
    queue<Node*> qu;

    // 진입차수가 0인 노드들을 추가한다
    for(int i=1; i<MAX_NODE; i++) {
        if(degree[i]==0) qu.push(g->nodes[i]);
    }

    // 정렬되어 나온 결과 개수는 그래프의 전체 노드의 개수와 같음
    for(int i=1; i<MAX_NODE; i++) {
        if(qu.empty()) {
            // 그래프 내부에 사이클이 발생한 경우
            // 모든 노드를 탐색하지 않았는데 큐가 비었다는 것은
            // 노드는 남아있는데 진입차수가 0인 노드가 없다는 것
            // 즉, 사이클이 발생 -> 위상정렬 불가능
            cout << "사이클 발생" << "\n";
            return;
        }

        Node* node = qu.front();
        qu.pop();
        result.push_back(node);

        // i번째 노드에서 출발하는 간선 차수 감소 시키기
        for(int j=0; j<node->adj.size(); j++) {
            Node* adj = node->adj.at(j);
            // adj의 인덱스 찾기
            auto it = find(g->nodes.begin(), g->nodes.end(), adj);
            if(it!=g->nodes.end()) {
                int index = it - g->nodes.begin();
                // 간선의 차수가 0인 항목들 queue에 추가시켜줌
                if((--degree[index])==0) qu.push(adj);
            }
        }
    }
}

int main() {
    Graph g;
    makeNode(&g, MAX_NODE);

    addDirectedEdge(&g, 1, 5);
    addDirectedEdge(&g, 1, 2);
    addDirectedEdge(&g, 2, 3);
    addDirectedEdge(&g, 3, 4);
    addDirectedEdge(&g, 4, 6);
    addDirectedEdge(&g, 5, 6);
    addDirectedEdge(&g, 6, 7);

    calcInDegree(&g);
    topologySort(&g);

    for(int i=0; i<result.size(); i++) {
        Node* node = result.at(i);
        cout << node->data << " ";
    }

    return 0;
}