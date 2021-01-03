#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int binSearch(int low, int high, int target) {
    if(low > high) return 0;
    else  {
        int mid = (low+high)/2;
        if(v[mid]==target) return 1;
        else if(v[mid] > target) return binSearch(low, mid-1, target);
        else return binSearch(mid+1, high, target);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int number;
        cin >> number;
        cout << binSearch(0, n-1, number) << " ";
    }

    return 0;
}