#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, budget;
    vector<int> v;
    
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    cin >> budget;
    sort(v.begin(), v.end());

    int low = 0, high = v[n-1];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;
        long long sum = 0;

        for(int i=0; i<n; i++) {
            if(v[i] < mid) sum += v[i];
            else sum += mid;
        }
        
        if(sum == budget) {
            cout << mid;
            return 0;
        }
        else if(budget < sum) {
            high = mid-1;
        }
        else if(sum < budget) {
            low = mid+1;
            ans = max(ans, mid);
        }
    }

    cout << ans;
    return 0;
}