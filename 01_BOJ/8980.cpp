#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct box_info {
    int start, end, item;
}box_info;

bool cmp(box_info a, box_info b) {
    if(a.end < b.end) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, capacity, box_total;
    int ans = 0;
    cin >> n >> capacity >> box_total;

    vector<box_info> v(box_total);
    vector<int> map(n+1, capacity);

    for(int i=0; i<box_total; i++) {
        cin >> v[i].start >> v[i].end >> v[i].item;
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<box_total; i++) {
        int mn = map[v[i].start];
        for(int j=v[i].start+1; j<v[i].end; j++) {
            mn = min(mn, map[j]);
        }

        int cnt = v[i].item;
        if(mn < cnt) cnt = mn;

        ans += cnt;

        for(int j=v[i].start; j<v[i].end; j++) {
            map[j] -= cnt;
        }
    }

    cout << ans;
    return 0;
}