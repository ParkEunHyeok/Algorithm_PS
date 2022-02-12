#include <iostream>
#include <cstring>
using namespace std;

int n;
int triangle[102][102];
int cache[102][102];
int countCache[102][102];

int path(int y, int x) {
    if(y==n-1) return triangle[y][x];

    int& ret = cache[y][x];
    if(ret!=-1) return ret;

    return ret = max(path(y+1,x),path(y+1,x+1))+triangle[y][x];
}

int count(int y, int x) {
    if(y==n-1) return 1;

    int& ret = countCache[y][x];
    if(ret!=-1) return ret;
    ret = 0;
    if(path(y+1,x)>=path(y+1,x+1)) ret += count(y+1, x);
    if(path(y+1,x+1)>=path(y+1,x)) ret += count(y+1, x+1);
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
            for(int j=0; j<=i; j++) {
                cin >> triangle[i][j];
            }
        }

        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));
        cout << count(0,0) << "\n";
    }

    return 0;
}