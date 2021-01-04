#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;    
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cout << v[0] << " ";
    for(int i=1; i<n; i++) {
        if(v[i-1] < v[i]) {
            cout << v[i] << " ";
        }
    }

    return 0;
}