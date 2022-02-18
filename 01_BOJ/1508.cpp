#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    vector<int> v;

    cin >> n >> m >> k;
    v.resize(k);
    for(int i=0; i<k; i++) {
        cin >> v[i];
    }

    int left = 0, right = n;
    int res = 0;

    while(left<=right) {
        int mid = (left+right)/2;
        int cnt = 1, last = v[0];

        for(int i=1; i<k; i++) {
            int diff = v[i] - last;
            if(diff >= mid) {
                cnt++;
                last = v[i];
            }
        }

        if(cnt >= m) {  // 간격을 늘여야함
            left = mid+1;
            res = mid;
        }
        else if(cnt < m) {  // 간격을 줄여야함
            right = mid-1;
        }
    }

    int last = v[0], cnt=1;
    cout << 1;
    for(int i=1; i<k; i++) {
        int diff = v[i] - last;
        if(cnt==m) {
            cout << 0;
            continue;
        }

        if(diff>=res) {
            cout << 1;
            last = v[i];
            cnt++;
        }
        else cout << 0;
    }

    return 0;
}