#include <stdio.h>

int n, m;   // nCm
int arr[9];
int visited[9];

void dfs(int idx) {
    if(idx==m) {
        for(int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++) {
        if(visited[i]==0) {
            // i가 순열에 포함
            visited[i] = 1;
            arr[idx] = i;
            dfs(idx+1);

            // i가 순열에 포함되지 않고 건너뜀
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(0);
    return 0;
}