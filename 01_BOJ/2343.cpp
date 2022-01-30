#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, sum = 0;
    cin >> n >> m;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        v[i] = tmp;
    }

    int left = 1, right = sum;
    int res = sum;

    while(left <= right) {
        int mid = (left+right)/2;
        int cnt = 1, s = 0;

        for(int i=0; i<n; i++) {
            if(v[i] > mid) {
                cnt = m + 1;
            }
            s += v[i];
            if(s > mid) {
                cnt++;
                s = v[i];
            }
        }

        if(cnt > m) left = mid + 1;
        else {
            right = mid - 1;
            if(res > mid) res = mid;
        }
    }

    cout << res;
    return 0;
}