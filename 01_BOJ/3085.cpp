#include <iostream>
using namespace std;

int n, res=0;
int map[52][52];

int candy() {
    int mx=0;

    for(int i=0; i<n; i++) {
        int tmp = 1;
        for(int j=1; j<n; j++) {
            if(map[i][j-1]==map[i][j]) tmp++;
            else {
                mx = max(mx, tmp);
                tmp = 1;
            }
        }
        mx = max(mx, tmp);
    }

    for(int i=0; i<n; i++) {
        int tmp = 1;
        for(int j=0; j<n-1; j++) {
            if(map[j][i]==map[j+1][i]) tmp++;
            else {
                mx = max(mx, tmp);
                tmp = 1;
            }
        }
        mx = max(mx, tmp);
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char a;
            cin >> a;
            map[i][j] = a-'A';
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // map[i][j]와 map[i][j+1] swap
            if(j+1<n && (map[i][j]!=map[i][j+1])) {
                swap(map[i][j], map[i][j+1]);
                res = max(res, candy());
                swap(map[i][j], map[i][j+1]);
            }

            // map[i][j]와 map[i+1][j] swap
            if(i+1<n && (map[i][j]!=map[i+1][j])) {
                swap(map[i][j], map[i+1][j]);
                res = max(res, candy());
                swap(map[i][j], map[i+1][j]);
            }
        }
    }

    cout << res;
    return 0;
}