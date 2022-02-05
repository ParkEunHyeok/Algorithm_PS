#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define NODE_SIZE 10000

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

bool visited[NODE_SIZE+1];  // 해당 노드를 선택했는지 여부 검사
vector<pair<int, int>> edges[NODE_SIZE+1];  // 간선 정보
int minimumDist[NODE_SIZE+1];   // i번째 노드를 연결하기위한 최소의 간선 비용 저장

int prim(int startNode, int nodeCount) {
    int result = 0;
    //초기화
    for(int i=1; i<=nodeCount; i++) {
        minimumDist[i] = INF;
        visited[i] = false;
    }

    minimumDist[startNode] = 0;

    for(int i=1; i<=nodeCount; i++) {
        int current = -1;   // 현재 선택된 노드
        int minDist = INF;  // 해당 노드까지의 비용

        // 반복문을 돌며 방문하지 않았고,
        // 현재 기준으로 비용이 최소인 간선을 탐색
        for(int j=1; j<=nodeCount; j++) {
            if((visited[j]==false) && (minDist > minimumDist[j])) {
                current = j;
                minDist = minimumDist[j];
            }
        }

        // 도달할 수 없는 노드가 존대
        if(current < 0) return INF; // 연결 그래프가 아님

        // 현재 선택된 노드가 비용이 가장 적은 노드임
        result += minDist;
        visited[current] = true;    // 현재 노드 방문 처리

        // 현재 노드에서 다른 노드로 나가는 간선을 검토하여
        // 다른 어떤 노드까지 도달하는 비용이 더 적은 간선이 존재하면 갱신
        for(int index=0; index<edges[current].size(); index++) {
            pair<int, int> pp = edges[current].at(index);
            int nextNode = pp.first;
            int nextDist = pp.second;

            // 현재 노드에서 다음 노드로 가는 간선 비용과,
            // 다른 기존의 어떤 노드에서 다음 노드로 가는 비용을 비교하여 더 작은값으로 갱신

            // (최소비용 간선 정보로 갱신함)
            minimumDist[nextNode] = min(minimumDist[nextNode], nextDist);
        }
    }

    return result;
}

int main() {
    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    int firstNode, secondNode, weight;
    for(int i=0; i<edgeCount; i++) {
        cin >> firstNode >> secondNode >> weight;
        edges[firstNode].push_back({secondNode, weight});
        edges[secondNode].push_back({firstNode, weight});
    }

    // 프림알고리즘을 시작할 임의의 노드 입력
    cout << prim(1, nodeCount);
}