#include <iostream>
#include <cstring>
using namespace std;
#define INF 987654321

int jump[5][5] = {{1,0,0,0,0},
                  {2,1,3,4,3},
                  {2,3,1,3,4},
                  {2,4,3,1,3},
                  {2,3,4,3,1}};
int len = 0;
int step[100004];
int cache[100004][5][5];

int dp(int idx, int left, int right) {
    if(idx==len) return 0;
    if((left!=0 && right!=0) && (left==right)) return INF;

    int &ret = cache[idx][left][right];
    if(ret!=-1) return ret;

    return ret = min(dp(idx+1,step[idx+1],right)+jump[step[idx+1]][left],
                     dp(idx+1,left,step[idx+1])+jump[step[idx+1]][right]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1) {
        int tmp;
        cin >> tmp;
        
        if(!tmp) break;

        step[len] = tmp;
        len++;
    }

    memset(cache, -1, sizeof(cache));

    cout << dp(0,0,0);
    return 0;
}