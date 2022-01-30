#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> path;

int find(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x<y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    parent.resize(n+1);

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int temp;
            cin >> temp;
            
            if(temp) {
                Union(i, j);
            }
        }
    }

    bool flag = true;
    int prev;
    for(int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        if(prev != find(temp) && i!=0) {
            flag = false;
            break;
        }
        prev = find(temp);
    }

    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}