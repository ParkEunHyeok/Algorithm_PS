#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1987654321;
int n, s;
int arr[102], pSum[102], pSqSum[102];
int cache[102][11];

// 정렬 & 부분합 미리 계산해놓기
void precalc() {
    sort(arr, arr+n);
    pSum[0] = arr[0];
    pSqSum[0] = arr[0] * arr[0];

    for(int i=1; i<n; i++) {
        pSum[i] = pSum[i-1] + arr[i];
        pSqSum[i] = pSqSum[i-1] + arr[i] * arr[i];
    }
}

// lo~hi 구간을 하나의 숫자로 표현할 때 최소 오차 합 계산 (누적합)
int minError(int lo, int hi) {
    int sum = pSum[hi] - (lo==0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo==0 ? 0 : pSqSum[lo-1]);
    int m = int(0.5 + (double)sum/(hi-lo+1));   // 평균 반올림

    // 종만북 249p 오차 제곱 합 수식으로 O(1)에 구할 수 있음.
    int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);
    return ret;
}

// from번째 이후의 숫자들을 parts개의 묶음으로 묶음.
int quantize(int from, int parts) {
    if(from==n) return 0;
    if(parts==0) return INF;

    int& ret = cache[from][parts];
    if(ret!=-1) return ret;
    ret = INF;

    // 조각의 길이를 변화시켜 가며 최소치를 찾는다.
    for(int i=1; from+i<=n; i++) {
        ret = min(ret, minError(from, from+i-1)+quantize(from+i, parts-1));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        cin >> n >> s;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        memset(cache, -1, sizeof(cache));
        precalc();
        cout << quantize(0, s) << "\n";
    }

    return 0;
}