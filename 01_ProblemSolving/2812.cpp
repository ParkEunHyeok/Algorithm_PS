#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n, k, cnt=0;
    string str, ans;
    stack<int> s;
    cin >> n >> k;
    cin >> str;

    int cur_num = 10;
    int num_idx = 0;
    int prev = 0;

    while(cnt!=k) {
        for(int i=prev; i<=n-1-cnt; i++) {
            if(cur_num > str[i]) {
                cur_num = str[i];
                num_idx = i;
            }
        }

        cnt++;
        ans.push_back(cur_num);
        prev = num_idx;
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}