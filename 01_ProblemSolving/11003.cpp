#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    cin >> n >> d;
    for(int i=1; i<=n; i++) {
        int temp;
        cin >> temp;
        pq.push({temp, i});

        while(pq.top().second < (i-d+1)) {
            pq.pop();
        }

        cout << pq.top().first << " ";
    }

    return 0;
}