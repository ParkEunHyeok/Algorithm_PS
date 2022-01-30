#include <stdio.h>

int v, e;   // v개 마을, E개 도로
int map[4002][4002];

void floyd_warshall() {
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            if(map[j][i]==0) continue;
            for(int k=1; k<=v; k++) {
                if(map[i][k]==0) continue;
                if(map[j][k]==0 || map[j][k] > map[j][i] + map[i][k]) {
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &v, &e);
    for(int i=0; i<e; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = c;
    }

    floyd_warshall();

    int min_cycle = 100000;
    for(int i=1; i<=v; i++) {
        int cycle = map[i][i];
        if(cycle==0) continue;
        if(min_cycle > cycle) {
            min_cycle = cycle;
        }
    }

    if(min_cycle==100000) printf("-1");
    else printf("%d", min_cycle);
    return 0;
}