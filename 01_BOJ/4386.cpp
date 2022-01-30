#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

int main() {
    int n;
    double res=0;
    vector<pdd> v;
    vector<pair<int, double> > a[102];
    int visited[102] = {0,};
    priority_queue<pdi, vector<pdi>, greater<pdi> > pq;

    cin >> n;
    for(int i=0; i<n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int x1 = v[i].first;
            int y1 = v[i].second;
            int x2 = v[j].first;
            int y2 = v[j].second;

            double d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

            a[i+1].push_back({j+1, d});
            a[j+1].push_back({i+1, d});
        }
    }

    pq.push({0, 1});

    while(!pq.empty()) {
        double w = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(visited[x]==1) continue;

        visited[x] = 1;
        res += w;

        for(int i=0; i<a[x].size(); i++) {
            int nx = a[x][i].first;
            double nw = a[x][i].second;
            pq.push({nw, nx});
        }
    }

    printf("%.2f", res);
    return 0;
}