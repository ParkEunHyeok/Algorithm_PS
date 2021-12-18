#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> v;
ll sum, result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    ll quota = sum / n;
    ll na = sum % n;
    //cout << quota << " " << na << "\n";

    for(int i=0; i<n; i++) {
        if(v[i] > quota) na--;
        if(v[i] < quota) {
            result += quota - v[i];
        }
    }

    if(na<0) na = 0;
    cout << result + na;
    return 0;
}