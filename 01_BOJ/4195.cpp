#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MAX 100001

vector<int> parent, Size;

int find(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;

    if(Size[x] < Size[y]) swap(x, y);
    parent[y] = x;
    Size[x] += Size[y];
    Size[y] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        parent.resize(2*n+1);
        Size.resize(2*n+1);

        for(int i=1; i<=(2*n); i++) {
            parent[i] = i;
            Size[i] = 1;
        }

        map<string, int> name;
        int idx = 1;

        for(int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;

            if(name.count(a)==0) name[a] = idx++;
            if(name.count(b)==0) name[b] = idx++;

            int aparent = find(name[a]);
            int bparent = find(name[b]);

            if(aparent==bparent) {
                cout << max(Size[aparent], Size[bparent]) << '\n';
            }
            else {
                Union(aparent, bparent);
                cout << max(Size[aparent], Size[bparent]) << '\n';
            }
        }
    }

    return 0;
}