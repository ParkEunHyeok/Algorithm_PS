#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, start, end;
    vector<pair<int, int>> v;

    cin >> n;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &start, &end);
        v.push_back(make_pair(end, start));
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    int last_end = 0;
    for(int i=0; i<n; i++) {
        if(last_end <= v[i].second) {
            last_end = v[i].first;
            cnt ++;
        }
    }

    cout << cnt;
    return 0;
}