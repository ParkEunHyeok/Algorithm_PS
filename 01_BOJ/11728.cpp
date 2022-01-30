#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sizeA, sizeB, tmp;
    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> sizeA, sizeB;

    for(int i=0; i<sizeA; i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    for(int i=0; i<sizeB; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}