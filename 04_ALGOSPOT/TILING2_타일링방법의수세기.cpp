#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cache[102];
    cache[0] = 1, cache[1] = 1;
    for(int i=2; i<=100; i++) {
        cache[i] = (cache[i-1] + cache[i-2]) % MOD;
    }

    int c, n;
    cin >> c;
    while(c--) {
        cin >> n;
        cout << cache[n] << "\n";
    }

    return 0;
}