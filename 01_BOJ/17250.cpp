#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> parent, rail;

ll find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m, a, b;
    cin >> n >> m;
    parent.resize(n+1);
    rail.resize(n+1);

    for(int i=1; i<=n; i++) {
        cin >> rail[i];
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        if(a>b) swap(a, b);
        if(find(a)!=find(b)) rail[find(a)] += rail[find(b)];
        cout << rail[find(a)] << "\n";
        Union(a, b);
    }

    return 0;
}