#include <iostream>
#include <vector>
using namespace std;

int n;
int mx_joy = 0;
vector<int> life, joy;

void gamsa(int idx, int l, int j) {
    if(l <= 0) return;
    if(idx>=n) {
        mx_joy = max(mx_joy, j);
        return;
    }

    gamsa(idx+1, l, j);
    gamsa(idx+1, l-life[idx], j+joy[idx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
    life.resize(n);
    joy.resize(n);

    for(int i=0; i<n; i++) {
        cin >> life[i];
    }
    for(int i=0; i<n; i++) {
        cin >> joy[i];
    }

    gamsa(0, 100, 0);

    cout << mx_joy;
    return 0;
}