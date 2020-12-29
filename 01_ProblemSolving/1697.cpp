#include <iostream>
#include <queue>
using namespace std;

bool visit[100002];

int bfs(int n, int k) {
    queue<pair<int, int>> q;
    visit[n] = true;
    q.push(make_pair(n,0));

    while(!q.empty()) {
        int location = q.front().first;
        int time = q.front().second;
        q.pop();

        if(location == k) return time;

        if(location+1<=100000 && visit[location+1]==false) {
            q.push(make_pair(location+1, time+1));
            visit[location+1] = true;
        }
        if(location-1>=0 && visit[location-1]==false) {
            q.push(make_pair(location-1, time+1));
            visit[location-1] = true;
        }
        if(location*2<=100000 && visit[location*2]==false) {
            q.push(make_pair(location*2, time+1));
            visit[location*2] = true;
        }
    }
}

int main() {
    int n, k;   // 수빈의 위치, 동생의 위치
    cin >> n >> k;

    cout << bfs(n,k);
    return 0;
}