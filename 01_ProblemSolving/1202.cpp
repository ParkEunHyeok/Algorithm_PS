#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    long long result = 0;
    vector<int> bag;
    vector<pii> jewel;
    priority_queue<int> pq;

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int weight, price;
        cin >> weight >> price;
        jewel.push_back(make_pair(weight, price));
    }
    for(int i=0; i<k; i++) {
        int size;
        cin >> size;
        bag.push_back(size);
    }

    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    int jewel_idx = 0;
    for(int i=0; i<k; i++) {
        while(jewel_idx<n && jewel[jewel_idx].first<=bag[i]) {
            pq.push(jewel[jewel_idx].second);
            jewel_idx++;
        }

        if(!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
    return 0;
}