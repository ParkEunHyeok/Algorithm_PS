#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int home, router, result=1;
    cin >> home >> router;

    vector<int> v(home);
    for(int i=0; i<home; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int low = 1, high = v[home-1] - v[0];
    while(low <= high) {
        int mid = (low + high) / 2;
        int home_cnt = 1, prev = v[0];

        for(int i=0; i<home; i++) {
            if(v[i] >= mid + prev) {
                home_cnt++;
                prev = v[i];
            }
        }

        if(home_cnt >= router) {
            low = mid + 1;
            result = mid;
        }
        else {  // home_cnt < router
            high = mid - 1;
        }
    }

    cout << result;
    return 0;
}