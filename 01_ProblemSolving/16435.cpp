#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int n, l;   // 과일의 개수, 스네이크버드의 초기 길이
    cin >> n >> l;
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        if(l>=v[i]) {
            l++;
        }
        else break;
    }

    cout << l;
    return 0;
}