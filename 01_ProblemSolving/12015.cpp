#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, prev=0;
    vector<int> v;
    cin >> n;
    v.push_back(0);

    for(int i=1; i<=n; i++) {
        int temp;
        cin >> temp;
        
        if(v.back() < temp) {
            v.push_back(temp);
        } else {
            int idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
            v[idx] = temp;
        }
    }

    cout << v.size()-1;
    return 0;
}