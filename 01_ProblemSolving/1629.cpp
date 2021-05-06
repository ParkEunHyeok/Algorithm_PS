#include <iostream>
#define ll unsigned long long
using namespace std;

ll a, b, c;

ll multiplication(ll a, ll b, ll c) {
    if(b==1) return a;
    else {
        ll n = multiplication(a, b/2, c);

        if(b%2==0) {   // b 짝수
            return (n * n) % c;
        }
        else  { // b 홀수
            return (n * n % c)*a%c;
        }
    }
}

int main() {
    cin >> a >> b >> c;
    if(b==1) {
        cout << a % c;
    }
    else cout << multiplication(a,b,c);
    return 0;
}