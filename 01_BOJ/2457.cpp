#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool time(pii a, pii b) {
    // int l[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(a.first<b.first) return 1;
    else if(a.first==b.first) {
        if(a.second<=b.second) return 1;
        else return 0;
    }
    else return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b, c, d;
    vector<pair<pii, pii>> v;
    pii m = {3, 1}, M = {0, 0}; 

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c >> d;
        v.push_back({{a, b}, {c, d}});
    }
    sort(v.begin(), v.end());

    int cnt = 1;
    bool flag = false;
    for(int i=0; i<n; i++) {
        pii s = v[i].first;
        pii e = v[i].second;

        if(time(s, m) && time(M, e)) {
            M = e;
        }
        else if(time(s, M) && time(M, e)) {
            m = M;
            M = e;
            cnt++;
        }

        if(time({12, 1}, M)) {
            flag = true;    
            break;
        }
    }

    if(flag) cout << cnt;
    else cout << 0;
    return 0;
}