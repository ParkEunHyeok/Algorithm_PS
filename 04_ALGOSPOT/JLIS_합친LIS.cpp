#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const ll NEGINF = numeric_limits<ll>::min();
int n, m;
int A[102], B[102];
int cache[102][102];

int jlis(int idxA, int idxB) {
    int& ret = cache[idxA+1][idxB+1];
    if(ret!=-1) return ret;

    ret = 2;
    ll a = (idxA==-1 ? NEGINF : A[idxA]);
    ll b = (idxB==-1 ? NEGINF : B[idxB]);
    ll maxElement = max(a, b);

    for(int i=idxA+1; i<n; i++) {
        if(maxElement < A[i])
            ret = max(ret, jlis(i, idxB)+1);
    }
    for(int i=idxB+1; i<m; i++) {
        if(maxElement < B[i])
            ret = max(ret, jlis(idxA, i)+1);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }
        for(int j=0; j<m; j++) {
            cin >> B[j];
        }
        memset(cache, -1, sizeof(cache));

        cout << jlis(-1, -1)-2 << "\n";
    }

    return 0;
}