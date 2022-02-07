#include <iostream>
using namespace std;

int n, m, res = 0;
char map[10002][502];
bool visited[10002][502];

bool OOB(int y, int x) {
    return (0<=y && y<n && 0<=x && x<m);
}

bool dfs(int y, int x) {
    visited[y][x] = true;
    if(x==m-1) {
        res++;
        return true;
    }

    if(OOB(y-1, x+1)) {
        if(map[y-1][x+1]=='.' && !visited[y-1][x+1]) {
            if(dfs(y-1, x+1)) return true;
        }
    }
    if(OOB(y, x+1)) {
        if(map[y][x+1]=='.' && !visited[y][x+1]) {
            if(dfs(y, x+1)) return true;
        }
    }
    if(OOB(y+1, x+1)) {
        if(map[y+1][x+1]=='.' && !visited[y+1][x+1]) {
            if(dfs(y+1, x+1)) return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++) dfs(i, 0);

    cout << res;
    return 0;
}