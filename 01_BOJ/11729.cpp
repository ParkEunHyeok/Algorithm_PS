#include <iostream>
using namespace std;

void func(int n, int a, int b) {
    if(n==1) {
        cout << a << " " << b << "\n";
        return;
    }

    func(n-1, a, 6-a-b);
    cout << a << " " << b << "\n";
    func(n-1, 6-a-b, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> k;

    cout << (1<<k)-1 << "\n";
    func(k, 1, 3);

    return 0;
}