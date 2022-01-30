#include <iostream>
using namespace std;

int n;
int arr[65][65];

void func(int n, int y, int x) {
    if(n==1) {
        cout << arr[y][x];
        return;
    }

    bool zero = false, one = false;

    for(int i=y; i<y+n; i++) {
        for(int j=x; j<x+n; j++) {
            if(arr[i][j]==1) one = true;
            else zero = true;
        }
    }

    if(one==true && zero==true) {
        n /= 2;
        cout << "(";
        func(n, y, x);
        func(n, y, x+n);
        func(n, y+n, x);
        func(n, y+n, x+n);
        cout << ")";
    }
    else if(one) cout << 1;
    else cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string str;

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> str;

        for(int j=1; j<=n; j++) {
            arr[i][j] = str[j-1] - '0';
        }
    }

    func(n, 1, 1);

    return 0;
}