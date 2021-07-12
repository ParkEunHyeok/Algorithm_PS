#include <iostream>
using namespace std;

int n, m;
int parent[1000002];

int find(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int mode, x, y;
        cin >> mode >> x >> y;
        if(mode==0) {
            Union(x, y);
        }
        else {
            x = find(x);
            y = find(y);
            if(x==y) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}