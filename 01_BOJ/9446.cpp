#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100004

int cnt;
int v[MAX];
int visited[MAX];
int done[MAX];

void dfs(int cur) {
    visited[cur] = true;
    int next = v[cur];

    if(!visited[next]) dfs(next);
    else if(!done[next]) {
        cnt++;
        while(next != cur) {
            cnt++;
            next = v[next];
        }
    }

    done[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cnt = 0;

        memset(v, 0, sizeof(v));
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));
        

        for(int i=1; i<=n; i++) {
            int temp;
            cin >> v[i];
            visited[i] = false;
        }

        for(int i=1; i<=n; i++) {
            if(visited[i]) continue;
            dfs(i);
        }

        cout << n-cnt << "\n";
    }

    return 0;
}