#include <iostream>
#include <vector>
using namespace std;

int n, result=0;
int cache[1001][1001];
vector<pair<pair<int, int>, int>> v;

void dp(int cur_str, int cur_int) {
    int& ret = cache[cur_str][cur_int];
    if(ret!=-1) return;
    ret = 0;

    int cur_pnt = 2;
    for(int i=0; i<n; i++) {
        int next_str = v[i].first.first;
        int next_int = v[i].first.second;
        int next_pnt = v[i].second;

        if(next_str <= cur_str || next_int <= cur_int) {
            ret++;
            cur_pnt += next_pnt;
        }
    }

    result = max(result, ret);
    cur_pnt -= cur_str + cur_int;
    
    for(int i=cur_str; i<=min(1000, cur_str + cur_pnt); i++) {
        dp(i, min(1000, cur_str+cur_pnt-i+cur_int));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a,b},c});
    }

    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            cache[i][j] = -1;
        }
    }

    dp(1,1);

    cout << result;
    return 0;
}