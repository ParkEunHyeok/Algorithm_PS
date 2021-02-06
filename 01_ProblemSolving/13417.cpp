#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<char> v;
        deque<char> dq;
        for(int i=0; i<n; i++) {
            char a;
            cin >> a;
            v.push_back(a);
        }

        int first = v.front() - 'A';
        dq.push_back(v.front());
        for(int i=1; i<n; i++) {
            if((v[i]-'A') <= first) {
                first = v[i] - 'A';
                dq.push_front(v[i]);
            }
            else dq.push_back(v[i]);
        }

        for(int i=0; i<n; i++) {
            cout << dq[i];
        }
        cout << "\n";
    }

    return 0;
}