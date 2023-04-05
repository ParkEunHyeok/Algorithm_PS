#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    int money = 0;
    int package = 987654321, piece = 987654321;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        package = min(package, a);
        piece = min(piece, b);
    }

    if(n<6) {
        if(package>=piece*n) {
            money += piece * n;
        } else {
            money += package;
        }
    } else {
        if(package>=piece*6) {
            money = piece * n;
        } else {
            money += package * (n/6);
            n = n/6;

            if(package>=piece*n) {
                money += piece * n;
            } else {
                money += package;
            }
        }
    }

    cout << money;
    return 0;
}