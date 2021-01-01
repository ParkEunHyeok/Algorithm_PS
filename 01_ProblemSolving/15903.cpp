#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#define ll long long

int main() {
    int n, m;   //카드의 개수, 합체 번수
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i=0; i<n; i++) {
        int number;
        scanf("%d", &number);
        pq.push(number);
    }

    for(int i=0; i<m; i++) {
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();

        pq.push(first+second);
        pq.push(first+second);
    }
    ll sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    printf("%lld", sum);
    return 0;
}