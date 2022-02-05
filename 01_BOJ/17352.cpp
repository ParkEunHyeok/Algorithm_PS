#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;
    parent.resize(n+1);

    for(int i=0; i<=n; i++)
        parent[i] = i;

    for(int i=0; i<n-2; i++) {
        cin >> a >> b;
        if(a>b) swap(a, b);
        Union(a, b);
    }

    for(int i=1; i<=n; i++) {
        if(find(i)!=0) {
            Union(0, i);
            cout << i << " ";
        }
    }
    return 0;
}