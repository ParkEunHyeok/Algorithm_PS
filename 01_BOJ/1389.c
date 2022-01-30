#include <stdio.h>

int n, m;   // 유저의 수, 친구 관계(간선)의 수
int map[102][102];

void floyd_warshall() {
    for(int i=1; i<=n; i++) {   // 경유
        for(int j=1; j<=n; j++) {   // 출발
            if(map[j][i]==0) continue;
            for(int k=1; k<=n; k++) {   // 도착
                if(map[i][k]==0 || j==k) continue;
                if(map[j][k]==0) {
                    map[j][k] = map[j][i] + map[i][k];
                } else if(map[j][k] > map[j][i] + map[i][k]) {
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
}

int main() {
    int min = 18181818, result = 0;   // 유저의 수, 친구 관계(간선)의 수
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    floyd_warshall();

    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=1; j<=n; j++) {
            sum += map[i][j];
        }
        if(min > sum) {
            min = sum;
            result = i;
        }
    }

    printf("%d", result);
    return 0;
}