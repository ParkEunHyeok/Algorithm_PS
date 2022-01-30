#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, ans=0;
    priority_queue<int, vector<int>, greater<int> > pq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size()!=1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a+b);
    }

    cout << ans;
    return 0;
}