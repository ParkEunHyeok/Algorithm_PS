#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, num1, num2;
        vector<pair<int, int> > v;
        cin >> n;

        for(int i=0; i<n; i++) {
            cin >> num1 >> num2;
            v.push_back(make_pair(num1, num2));
        }
        sort(v.begin(), v.end());

        int cnt = 0, tmp=1000000;
        for(int i=0; i<n; i++) {
            if(v[i].second < tmp) {
                tmp = v[i].second;
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}