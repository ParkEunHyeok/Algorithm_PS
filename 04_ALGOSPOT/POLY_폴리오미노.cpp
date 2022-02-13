#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 10000000;
int cache[102][102];

// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의
// 정사각형을 포함하는 폴리오미노의 수를 반환한다.
int poly(int n, int first) {
    if(n==first) return 1;

    int& ret = cache[n][first];
    if(ret!=-1) return ret;
    ret = 0;

    for(int i=1; i<=n-first; i++) {
        int add = i + first - 1;
        add *= poly(n-first, i);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        int n, res=0;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        
        for(int i=1; i<=n; i++) {
            res += poly(n, i);
            res %= MOD;
        }
        cout << res << "\n";
    }

    return 0;
}