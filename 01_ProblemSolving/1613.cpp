#include <iostream>

using namespace std;

int n, m;   // 사건의 개수, 간선의 개수
int map[402][402];

void floyd_warshall() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[j][i]==0) continue;
            for(int k=1; k<=n; k++) {
                if(map[i][k]==0 || j==k) continue;
                if(map[j][k]==0) {  // 전후관계가 명확하지 않은 경우
                    if(map[j][i]==-1 && map[i][k]==-1) {
                        // j>i>k 순으로 전후 관계가 정해질 때
                        // j > k 가 성립.
                        map[j][k] = -1;
                    }
                    if(map[j][i]==1 && map[i][k]==1) {
                        // k>i>j 순으로 전후 관계가 정해질 때
                        // k > j 가 성립.
                        map[j][k] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        //이전에 일어남 : -1, 이후에 일어남 : 1
        map[a][b] = -1;
        map[b][a] = 1;
    }

    floyd_warshall();

    int s;
    scanf("%d", &s);
    for(int i=0; i<s; i++) {
        int front, back;
        scanf("%d%d", &front, &back);
        printf("%d\n", map[front][back]);
    }

    return 0;
}