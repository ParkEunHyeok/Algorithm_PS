#include <iostream>
#include <queue>
using namespace std;
#define INF 1987654321
#define ll long long

int a,b;
ll res = -1;
queue<pair<ll, int>> q;

int bfs(ll num, int cnt) {
    q.push({num, cnt});

    while(!q.empty()) {
        ll value = q.front().first;
        int ccnt = q.front().second;
        q.pop();

        if(value==b) return ccnt;

        if(value*2 <= b) q.push({value*2, ccnt+1});
        if(value*10+1 <= b) q.push({value*10+1,ccnt+1});
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;

    cout << bfs(a, 1);

    return 0;
}