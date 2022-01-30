#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;

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

    scanf("%d%d", &n, &m);
    parent.resize(n);
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        
        if(find(a)==find(b)) {
            printf("%d", i+1);
            return 0;
        }
        Union(a, b);
    }

    printf("0");
    return 0;
}