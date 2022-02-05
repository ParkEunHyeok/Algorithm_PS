#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000002

int parent[MAX], cnt[MAX];

int find(int x) {
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

    int n, a, b;
    char m;
    for(int i=1; i<=1000000; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }

    cin >> n;
    while(n--) {
        cin >> m;

        if(m=='I') {
            cin >> a >> b;
            if(a>b) swap(a, b);
            if(find(a)!=find(b))
                cnt[find(a)] += cnt[find(b)];
            Union(a, b);
        } else {
            cin >> a;
            cout << cnt[find(a)] << "\n";
        }
    }

    return 0;
}