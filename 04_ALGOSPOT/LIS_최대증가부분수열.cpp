#include <iostream>
#include <cstring>
using namespace std;

int n;
int s[502], cache[502];

int lis(int start) {
    int& ret = cache[start];
    if(ret!=-1) return ret;

    ret = 1;
    for(int i=start+1; i<n; i++) {
        if(s[start] < s[i]) {
            ret = max(ret, lis(i)+1);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> s[i];
        }
        memset(cache, -1, sizeof(cache));

        int res=0;
        for(int i=0; i<n; i++) {
            res = max(res, lis(i));
        }

        cout << res << "\n";
    }

    return 0;
}