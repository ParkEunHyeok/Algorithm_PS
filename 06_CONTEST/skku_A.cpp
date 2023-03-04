#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if((n+m-1)>k) {
        cout << "NO";
        return 0;
    } else cout << "YES\n";

    for(int i=1; i<=n; i++) {
        for(int j=i; j<m+i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}