#include <stdio.h>

int n, m;
int arr[9];
int visited[9];

void dfs(int cnt, int idx) {
    if(cnt==m) {
        for(int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=idx; i<=n; i++) {
        if(visited[i]==0) {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(cnt+1, i+1);

            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(0,1);
    return 0;  
}