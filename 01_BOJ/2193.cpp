#include <iostream>
using namespace std;
#define ll long long

ll dynamic(int n) {
    ll arr[92];
    arr[1] = 1, arr[2] = 1;
    for(int i=3; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int main() {
    int n;
    cin >> n;

    cout << dynamic(n);
    return 0;
}