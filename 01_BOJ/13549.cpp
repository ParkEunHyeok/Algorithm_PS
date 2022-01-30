#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321
typedef pair<int, int> pii;

int subin, target;
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool visit[100002];
int dist[100002];

void dijkstra() {
    pq.push({0, subin});
    dist[subin] = 0;

    while(!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        visit[now] = true;

        int next, cost;
        for(int i=0; i<3; i++) {
            if(i==0) {
                next = now - 1;
                cost = 1;
            }
            else if(i==1) {
                next = now + 1;
                cost = 1;
            }
            else {
                next = now * 2;
                cost = 0;
            }

            if(next<0 || next>100000 || visit[next]) continue;

            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                pq.push({dist[next], next});
            }
        }
        if(now==target) break;
    }
}

int main() {
    cin >> subin >> target;

    for(int i=0; i<=100000; i++) {
        dist[i] = INF;
    }
    
    dijkstra();

    cout << dist[target];
    return 0;
}