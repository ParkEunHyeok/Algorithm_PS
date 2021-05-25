#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int, int>

bool compare(pii a, pii b) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    int lo, hi;
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    cin >> n >> d;
    for(int i=1; i<=n; i++) {
        lo = i + 1 - d;
        hi = i;

        int temp;
        cin >> temp;
    }
}