#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int k, n;
        char c;
        bool visited[1000002] = {0,};
        priority_queue<pii> max_pq;
        priority_queue<pii, vector<pii>, greater<pii>> min_pq;

        cin >> k;
        for(int i=0; i<k; i++) {
            cin >> c >> n;

            if(c=='I') {
                visited[i] = true;
                min_pq.push({n, i});
                max_pq.push({n, i});
            }
            else {
                while(!min_pq.empty()) {
                    if(!visited[min_pq.top().second]) min_pq.pop();
                    else break;
                }
                while(!max_pq.empty()) {
                    if(!visited[max_pq.top().second]) max_pq.pop();
                    else break;
                }

                if(n==1) {
                    if(max_pq.empty()) continue;
                    visited[max_pq.top().second] = false;
                    max_pq.pop();
                } else {
                    if(min_pq.empty()) continue;
                    visited[min_pq.top().second] = false;
                    min_pq.pop();
                }
            }
        }
        
        while(!min_pq.empty()) {
            if(!visited[min_pq.top().second]) min_pq.pop();
            else break;
        }
        while(!max_pq.empty()) {
            if(!visited[max_pq.top().second]) max_pq.pop();
            else break;
        }
        if(min_pq.empty()) cout << "EMPTY\n";
        else cout << max_pq.top().first << " " << min_pq.top().first <<  "\n";
    }

    return 0;
}