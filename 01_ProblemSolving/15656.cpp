#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[10];
int arr[10];

void dfs(int cnt, int idx) {
    if(cnt==m) {
        for(int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i<n; i++) {
        arr[cnt] = map[i];
        dfs(cnt+1, i);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &map[i]);
    }

    sort(map, map+n);
    dfs(0,0);

    return 0;
}