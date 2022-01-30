#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, n;   // 가진 랜선의 개수, 필요한 랜선의 개수
    vector<int> v;

    cin >> k >> n;
    v.resize(k);
    for(int i=0; i<k; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll low = 1, high = v[k-1];
    ll result = 0;
    while(low <= high) {
        ll mid = (low + high) / 2;
        ll sum = 0;

        for(int i=0; i<k; i++) {
            sum += v[i] / mid;
        }

        if(sum >= n) {
            low = mid + 1;
            result = max(result, mid);
        }
        else {
            high = mid - 1;
        }
    }

    cout << result;
    return 0;
}