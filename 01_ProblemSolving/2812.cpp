#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k, K;
    string str;
    deque<int> dq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> str;
    K = k;

    for(int i=0; i<n; i++) {
        while(!dq.empty() && k>0 && dq.back()<(str[i]-'0')) {
            dq.pop_back();
            k--;
        }

        dq.push_back(str[i]-'0');
    }

    for(int i=0; i<n-K; i++) cout << dq[i];
    return 0;
}