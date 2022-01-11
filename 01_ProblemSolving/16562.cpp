#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int res = 0;
vector<int> v, parent;

int find(int x) {
    if(parent[x]==x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    parent[y] = x;
}

int main() {
    int a, b;
    bool flag = false;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    v.resize(n+2);
    parent.resize(n+2);
    
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        if(v[find(a)] > v[find(b)]) swap(a, b);
        Union(a, b);
    }

    for(int i=1; i<=n; i++) {
        int pi = find(i);
        if(pi==0) continue;

        int money = v[pi];
        k -= money;
        res += money;
        Union(0, i);

        if(k<0) {
            flag = true;
            break;
        }
    }

    if(flag) cout << "Oh no";
    else cout << res;
    return 0;
}