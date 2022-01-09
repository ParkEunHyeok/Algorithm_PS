#include <iostream>
#include <vector>
using namespace std;

int n, m, know, res = 0;
int parent[52];
vector<int> v[52];
vector<int> know_truth;

int find(int x) {
    if(parent[x]==x) return x;
    else return find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    parent[y] = x;
}

int main() {
    int party, tmp;
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> know;

    parent[0] = 0;
    for(int i=0; i<know; i++) {
        cin >> tmp;
        know_truth.push_back(tmp);
        parent[tmp] = tmp;
    }

    for(int i=0; i<m; i++) {
        cin >> party;

        for(int j=0; j<party; j++) {
            cin >> tmp;
            parent[tmp] = tmp;
            v[i].push_back(tmp);
        }
    }

    for(int i=0; i<m; i++) {
        int n1 = v[i][0];
        for(int j=1; j<v[i].size(); j++) {
            Union(n1, v[i][j]);
        }
    }

    for(int i=0; i<know; i++) {
        Union(0, know_truth[i]);
    }

    for(int i=0; i<m; i++) {
        if(find(v[i][0])!=0) res++;
    }

    cout << res;
    return 0;
}