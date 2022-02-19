#include <iostream>
#include <vector>
using namespace std;
#define INF 1987654321
#define NODE_COUNT 6

/*
    최단거리
    정답 : 0 2 3 1 2 4
*/

// 간선 정보를 저장할 배열
int edges[NODE_COUNT][NODE_COUNT] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0},
};

bool visited[NODE_COUNT] = {0,};
int dists[NODE_COUNT] = {0,};

// distance 배열에서 모든 노드를 탐색하여 가장 적은 값을 가지는 노드를 반환
int getSmallIndex() {
    int minValue = INF;
    int minIndex = INF;
    for(int i=0; i<NODE_COUNT; i++) {
        if(visited[i]==true) continue;
        if(dists[i] < minValue) {
            minValue = dists[i];
            minIndex = i;
        }
    }

    return minIndex;
}

/*
    다익스트라
    1. dists 배열을 시작노드의 값으로 초기화함
    2. 시작노드 방문처리
    3. 최단거리를 계산해나갈 배열 dists에서 가장 최소거리를 가지는 최솟값
*/
void dijkstra(int startNode) {
    // 1. dists 배열을 시작노드의 값으로 초기화함
    for(int i=0; i<NODE_COUNT; i++) dists[i] = edges[startNode][i];

    // 2. 시작노드 방문처리
    visited[startNode] = true;

    // 시작노드는 방문하였으므로 NODE_COUNT-1까지 확인
    for(int i=0; i<NODE_COUNT; i++) {
        // 3. 최단거리를 계산해나갈 배열 dists에서 가장 최소거리를 가지는 최솟값
        int current = getSmallIndex();
        if(current==INF) continue;

        visited[current] = true;
        // 모든 노드를 검사하여 j번째 노드를 거쳐가는 경우의 비용이 더 작다면 갱신함
        for(int j=0; j<NODE_COUNT; j++) {
            if(visited[j]) continue;
            
            // 현재 선택된 노드(dists[current])를 거쳐갈 경우 더 적은값을 가지는지 확인함
            // 거쳐가는 경우 - dists[current] + edges[current]
            // 한번에 가는 경우 dists[j]
            if(dists[j] > dists[current] + edges[current][j])
                dists[j] = dists[current] + edges[current][j];
        }
    }
}

// 다익스트라 최단경로 출력
void printDiskstra() {
    cout << endl;
    for(int i=0; i<NODE_COUNT; i++) {
        cout << dists[i] << " ";
    }
}

int main() {
    for(int i=0; i<NODE_COUNT; i++) {
        dists[i] = INF;
    }

    dijkstra(0);
    printDiskstra();
}