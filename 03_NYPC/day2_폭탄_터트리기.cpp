#include <iostream>
#include <vector>
using namespace std;
#define MAX 300001

vector<int> v(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    int res = 1;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }

    int mn = 1987654321, mx = 0;
    for(int i=0; i<n; i++) {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        if(mx-mn>k) {
            res++;
            mn = 1987654321, mx = 0;
            mx = max(mx, v[i]);
            mn = min(mn, v[i]);
        }
    }

    cout << res;
    return 0;
}