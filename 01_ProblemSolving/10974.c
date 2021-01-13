#include <stdio.h>

int n;
int arr[10];

void dfs(int cnt) {
    if(cnt==n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(arr[i]==arr[j]) return;
            }
        }
        for(int i=0; i<n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i<n; i++) {
        arr[cnt] = i+1;
        dfs(cnt+1);
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}