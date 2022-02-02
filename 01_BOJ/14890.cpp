#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, l;
    int map[102][102];

    cin >> n >> l;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    int slope = 0, res = 0;

    for(int i=0; i<n; i++) {
        bool flag = true;
        int prev = map[i][0];
        slope = 1;

        for(int j=1; j<n; j++) {
            if(prev==map[i][j]) slope++;
            else if(prev-map[i][j]==1) { // 내리막
                if(slope>=0) {
                    slope = 1-l;
                    prev = map[i][j];
                } else {
                    flag = false;
                    break;
                }
            }
            else if(prev-map[i][j]==-1) {   // 오르막
                if(slope>=l) {
                    slope = 1;
                    prev = map[i][j];
                } else {
                    flag = false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }
        }
        if(slope<0) continue;
        if(flag) res++;
    }

    for(int i=0; i<n; i++) {
        bool flag = true;
        int prev = map[0][i];
        slope = 1;

        for(int j=1; j<n; j++) {
            if(prev==map[j][i]) slope++;
            else if(prev-map[j][i]==1) { // 내리막
                if(slope>=0) {
                    slope = 1-l;
                    prev = map[j][i];
                } else {
                    flag = false;
                    break;
                }
            }
            else if(prev-map[j][i]==-1) {   // 오르막
                if(slope>=l) {
                    slope = 1;
                    prev = map[j][i];
                } else {
                    flag = false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }
        }
        if(slope<0) continue;
        if(flag) res++;
    }

    cout << res;
    return 0;
}