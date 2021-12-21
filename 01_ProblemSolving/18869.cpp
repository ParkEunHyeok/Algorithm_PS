#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> v(m), arr(m);
    vector<string> res;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[j];
            arr[j] = v[j];
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        string vec = "";
        for(int i=0; i<m; i++) {
            vec += lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        }
        res.push_back(vec);
    }

    int cnt = 1, ans = 0;
    sort(res.begin(), res.end());
    for(int i=1; i<n; i++) {
        if(res[i]==res[i-1]) cnt++;
        else {
            // 중복되는 만큼 nC2 카운트
            ans += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    ans += cnt*(cnt-1)/2;

    cout << ans;
    return 0;
}