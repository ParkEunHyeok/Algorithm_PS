#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;

    cin >> t;
    while(t--) {
        int n, m;

        cin >> n;
        vector<int> v(n);

        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        cin >> m;
        for(int i=0; i<m; i++) {
            int target;
            bool flag = false;
            cin >> target;

            int low = 0, high = n-1;
            while(low <= high) {
                int mid = (low + high) / 2;

                if(v[mid]==target) {
                    cout << 1 << "\n";
                    flag = true;
                    break;
                }
                else if(v[mid] < target) {
                    low = mid + 1;
                }
                else if(target < v[mid]) {
                    high = mid - 1;
                }
            }
            if(!flag) cout << 0 << "\n";
        }
    }

    return 0;
}