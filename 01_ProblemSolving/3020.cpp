#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, h;
    cin >> n >> h;
    
    vector<int> bot(n/2), top(n/2);
    int res=200001, same=0;
    
    for(int i=0; i<n/2; i++) {
        cin >> bot[i] >> top[i];
    }
    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());

    for(int i=1; i<=h; i++) {
        int cnt = 0;
        cnt += (n/2)-(lower_bound(bot.begin(), bot.end(), i)-bot.begin());
        cnt += (n/2)-(upper_bound(top.begin(), top.end(), h-i)-top.begin());
    
        if(res==cnt) same++;
        else if(res > cnt) {
            res = cnt;
            same = 1;
        }
    }

    cout << res << " " << same;
    return 0;
}