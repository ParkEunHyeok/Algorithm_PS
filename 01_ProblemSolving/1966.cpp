#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, m;   // 테스트케이스의 개수, 문서의 개수, 궁금한 순서의 문서
    cin >> t;
    while(t--) {
        cin >> n >> m;
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for(int i=0; i<n; i++) {
            int important;
            cin >> important;
            q.push(make_pair(i, important));
            pq.push(important);
        }

        int cnt = 0;
        while(!pq.empty()) {
            int idx = q.front().first;
            int va = q.front().second;
            q.pop();

            if(pq.top()==va) {
                pq.pop();
                cnt ++;
                if(idx==m) break;
            }
            else q.push(make_pair(idx, va));
        }

        cout << cnt << "\n";
    }
}