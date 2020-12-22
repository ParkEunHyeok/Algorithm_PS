#include <iostream>
#include <cstring>

using namespace std;

const int INF = 100001;
int map[101][101];
int n, m;  // 도시의 개수, 버스의 개수

void floyd_warshall() {
    for(int i=1; i<=n; i++) {   // i번째 vertex 경유
        for(int j=1; j<=n; j++) {   // a vertex
            if(map[j][i]==0) continue; 
            for(int k=1; k<=n; k++) {   // b vertex
                if(map[i][k]==0 || j==k) continue;
                if(map[j][k]==0 || map[j][k] > map[j][i] + map[i][k]) {
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