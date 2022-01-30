#include <iostream>
#include <vector>
using namespace std;

int g, p, res = 0;
int ap[100002];
int parent[100002];

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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> g >> p;

    for(int i=1; i<=p; i++) {
        cin >> ap[i];
    }

    for(int i=0; i<=g; i++) {
        parent[i] = i;
    }

    for(int i=1; i<=p; i++) {
        int gi = find(ap[i]);

        if(gi!=0) {
            res++;
            Union(gi-1, gi);
        } else break;
    }

    cout << res;
    return 0;
}