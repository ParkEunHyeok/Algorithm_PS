#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int parent[1002];
vector<tuple<double, int, int>> edge;

int find(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return false;

    if(x>y) swap(x, y);
    parent[y] = x;
    return true;
}

int main() {
    int n, m;
    vector<pair<int, int>> v;

    for(int i=0; i<=1000; i++) {
        parent[i] = i;
    }

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        is_diff_group(x, y);
    }

    for(int i=0; i<n-1; i++) {
        int x1 = v[i].first;
        int y1 = v[i].second;
        for(int j=i+1; j<n; j++) {    
            int x2 = v[j].first;
            int y2 = v[j].second;

            double d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
            edge.push_back(make_tuple(d, i+1, j+1));
        }
    }
    sort(edge.begin(), edge.end());
    
    double res = 0;
    for(int i=0; i<edge.size(); i++) {
        double dist;
        int a, b;
        tie(dist, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        res += dist;
    }

    printf("%.2f", res);
    return 0;
}