#include <stdio.h>

int n, m;
int arr[10];
int visited[10];

void dfs(int cnt, int idx) {
    if(cnt==m+1) {
        for(int i=1; i<=m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=idx; i<=n; i++) {
        if(arr[cnt-1]<=i) {
            arr[cnt] = i;
            dfs(cnt+1,idx);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(1,1);
    return 0;
}