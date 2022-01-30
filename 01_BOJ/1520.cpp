#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> v, cache;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int dfs(int y, int x) {
    if(y==n-1 && x==m-1) return 1;

    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    ret = 0;

    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(nextY>=0 && nextX>=0 && nextY<n && nextX<m) {
            if(v[y][x]>v[nextY][nextX]) {
                ret += dfs(nextY, nextX);
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    cache.resize(n, (vector<int>(m,-1)));

    for(int i=0; i<n; i++) {
        vector<int> tmp(m);
        for(int j=0; j<m; j++) {
            cin >> tmp[j];
        }
        v.push_back(tmp);
    }

    cout << dfs(0,0);
    return 0;
}