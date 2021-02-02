#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int n;
long long ans = 0;
long long mx=0;
int arr[1000002] = {0,};


int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        n = 0;
        memset(arr, 0, sizeof(arr));
        ans = 0;
        mx = 0;
        cin >> n;

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        for(int i=n-1; i>=0; i--) {
            mx = max(mx, arr[i]);
            ans += mx - arr[i];
        }

        cout << ans << "\n";
    }

    return 0;
}