#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> result;

void BackTracking(int cnt, int num) {
    if(cnt==m) {
        for(int i=0; i<m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;

    for(int i=num; i<n; i++) {
        if(prev != v[i]) {
            result[cnt] = v[i];
            prev = v[i];
            BackTracking(cnt+1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    v.resize(n);
    result.resize(m);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    BackTracking(0,0);

    return 0;
}