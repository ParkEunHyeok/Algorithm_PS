#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    vector<ll> v;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll res = 3000000001;
    int a, b, c;

    for(int i=0; i<n-2; i++) {
        int j = i+1, k=n-1;

        while(j<k) {
            ll sum = v[i] + v[j] + v[k];

            if(llabs(sum) < res) {
                res = llabs(sum);
                a=i, b=j, c=k;
            }

            if(sum>0) k--;
            else j++;
        }
    }

    cout << v[a] << " " << v[b] << " " << v[c];
    return 0;
}