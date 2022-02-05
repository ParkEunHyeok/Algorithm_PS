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

    int t;
    cin >> t;

    for(int tk=1; tk<=t; tk++) {
        cout << "Scenario " << tk << ":\n";

        int n, m, a, b;
        cin >> n;
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;

        cin >> m;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            if(a>b) swap(a, b);
            Union(a, b);
        }

        cin >> m;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            if(find(a)==find(b)) cout << "1\n";
            else cout << "0\n";
        }

        cout << "\n";
    }

    return 0;
}