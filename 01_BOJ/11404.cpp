#include <iostream>
#include <cstring>

using namespace std;

const int INF = 100001;
int map[101][101];
int n, m;  // 도시의 개수, 버스의 개수

void floyd_warshall() {
    for(int i=1; i<=n; i++) {   // i번째 vertex 경유
        for(int j=1; j<=n; j++) {   // a vertex
            if(map[j][i]==0) continue;  // 시작점과 간선이 연결 안 된 경우
            for(int k=1; k<=n; k++) {   // b vertex
                if(map[i][k]==0 || j==k) continue;  // 간선과 도착점이 연결 안 된 경우
                if(map[j][k]==0 || map[j][k] > map[j][i] + map[i][k]) {
                    // 시작점과 도착점의 거리가 갱신 되지 않았거나
                    // 더 거리가 적다면
                    // 더 적은 거리로 갱신
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(!map[a][b]) map[a][b] = c;
        else map[a][b] = min(map[a][b], c);
    }

    floyd_warshall();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}