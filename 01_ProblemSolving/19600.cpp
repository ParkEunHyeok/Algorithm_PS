#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll b[5001][5001];
ll t[5001][5001];

void binary_search(int i, int left, int right, int depth) {
    if(left>right) return;
    
    int mid = (left + right)/2;
    b[i][mid] = depth;
    
    binary_search(i, left, mid-1, depth+1);
    binary_search(i, mid+1, right, depth+1);
}

void ternary_search(int i, int left, int right, int depth) {
    if(left>right) return;
    
    int left_third = left + (right - left) / 3;
    int right_third = right - (right - left) / 3;
    
    t[i][left_third] = depth;
    t[i][right_third] = depth+1;

    ternary_search(i, left, left_third-1, depth+1);
    ternary_search(i, left_third+1, right_third-1, depth+1);
    ternary_search(i, right_third+1, right, depth+1);
}

int main() {
    int q;

    for(int i=1; i<=5000; i++) {
        binary_search(i, 0, i-1, 0);
        ternary_search(i, 0, i-1, 0);

        for(int j=1; j<i; j++) {
            b[i][j] += b[i][j-1];
            t[i][j] += t[i][j-1];
        }
    }

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;

    while(q--) {
        int n, s, e;
        int sumT, sumB;
        cin >> n >> s >> e;

        if(s==0) sumT = t[n][e];
        else sumT = t[n][e] - t[n][s-1];

        if(s==0) sumB = b[n][e];
        else sumB = b[n][e] - b[n][s-1];

        cout << sumT - sumB << "\n";
    }

    return 0;
}