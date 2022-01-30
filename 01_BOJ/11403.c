#include <stdio.h>

int map[102][102];
int n;

void floyd_warshall() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[j][i]==0) continue;
            for(int k=1; k<=n; k++) {
                if(map[i][k]==0) continue;
                if(map[j][k]==0 || map[j][k] > map[j][i] + map[i][k]) {
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int from = i, to = j, cost;
            scanf("%d", &cost);
            if(!map[from][to]) map[from][to] = cost;
            else if(map[from][to] > cost) map[from][to] = cost;
            else continue; 
        }
    }

    floyd_warshall();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }

    return 0;
}