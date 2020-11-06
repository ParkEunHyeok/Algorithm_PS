#include <iostream>
#include <queue>

int main() {
    int map[1001][1001] = {0,};
    int visit[1001] = {0,};
    int n, m, v; // 정점의 개수, 간선의 개수, 탐색 시작 번호
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0; i<m; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        map[num1][num2] = 1;
        map[num2][num1] = 1;
    }

    
}