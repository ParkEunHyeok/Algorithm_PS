#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, tmp;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> tmp;
            pq.push(tmp);
            if(pq.size()>n) pq.pop();
        }
    }

    cout << pq.top();
    return 0;
}