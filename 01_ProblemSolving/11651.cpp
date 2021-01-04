#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int> > v;    
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y,x));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        cout << v[i].second << " ";
        cout << v[i].first << "\n";
    }

    return 0;
}