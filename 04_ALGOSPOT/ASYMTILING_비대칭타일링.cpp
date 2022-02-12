#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int n;
int cache[102];

void tiling() {
    cache[0] = 1, cache[1] = 1;
    for(int i=2; i<=100; i++) {
        cache[i] = (cache[i-1]+cache[i-2]) % MOD;
    }
}

int asymmetric(int width) {
    if(width % 2 == 1) 
        return (cache[width] - cache[width/2] + MOD) % MOD;
    
    int ret = cache[width];
    ret = (ret - cache[width/2] + MOD) % MOD;
    ret = (ret - cache[(width/2)-1] + MOD) % MOD;
    return ret; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    tiling();

    while(c--) {
        cin >> n;
        cout << asymmetric(n) << "\n";
    }

    return 0;
}