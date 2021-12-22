#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll d, n, m, k;
    scanf("%lld%lld%lld%lld",&d, &n, &m, &k);

    ll jja=0, jjam=0, bok=0;
    jja = d-(n%d);
    jjam = d-(m%d);
    bok = k%d;
    ll res;
    
    

    printf("%lld", res + bok);
    return 0;
}