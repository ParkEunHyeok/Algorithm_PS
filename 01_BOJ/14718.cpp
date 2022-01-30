#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000001

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, target;
    int cnt = 0;
    int A = MAX, B = MAX, C = MAX;
    int res = 987654321;
    cin >> n >> target;

    vector<int> force, speed, intellect;
    force.resize(n);
    speed.resize(n);
    intellect.resize(n);
    for(int i=0; i<n; i++) {
        cin >> force[i] >> speed[i] >> intellect[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                int curf = force[i], curs = speed[j], curi = intellect[k];
                cnt = 0;
                
                for(int l=0; l<n; l++) {
                    if(curf>=force[l] && curs>=speed[l] && curi>=intellect[l]) {
                        cnt++;
                    }
                }
                if(cnt>=target && res>=cnt && curf+curs+curi<A+B+C) {
                    A = curf;
                    B = curs;
                    C = curi;
                    res = cnt;
                }
            }
        }
    }

    cout << A+B+C;
    return 0;
}