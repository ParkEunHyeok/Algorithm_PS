#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, dasom, tmp;
    int result = 0;
    priority_queue<int, vector<int>, less<int> > pq;

    cin >> n >> dasom;
    for(int i=0; i<n-1; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    while(!pq.empty() && pq.top() >= dasom) {
        tmp = pq.top();
        pq.pop();
        tmp--;
        dasom++;
        pq.push(tmp);
        result++;
    }

    cout << result;
    return 0;
}