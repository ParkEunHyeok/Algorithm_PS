#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    vector<int> arr, v;

    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        arr.push_back(num);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0; i<n; i++) {
        int out = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        cout << out << " ";
    }

    return 0;
}