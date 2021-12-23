#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll d, n, m, k;
    cin >> d >> n >> m >> k;

    ll jja = d - (n%d);
    ll jjam = d - (m%d);
    ll bok = (k%d);
    ll result = d*(k/d);

    if(bok >= jja + jjam) {
        result += bok - jja - jjam;
    } else if(bok >= jja || bok >= jjam) {
        if(bok >= jja && bok >= jjam) {
            result += min(bok-jja, bok-jjam);
        } else {
            if(bok >= jja) result += bok-jja;
            else result += bok-jjam;
        }
    } else if(bok+d >= jja + jjam && (k/d) >= 1) {
        result -= d;
        result += bok + d - jja - jjam;
    } else {
        result += bok;
    }

    cout << result;
    return 0;
}