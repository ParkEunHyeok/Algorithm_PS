#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[10];
int arr[10];
bool visited[10] = {false,};

void dfs(int cnt) {
    if(cnt==m) {
        for(int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    bool isused[10002] = {false,};
    for(int i=0; i<n; i++) {
        if(visited[i]==false && isused[map[i]]==false) {
            isused[map[i]] = true;
            visited[i] = true;
            arr[cnt] = map[i];
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &map[i]);
    }

    sort(map, map+n);
    dfs(0);

    return 0;
}