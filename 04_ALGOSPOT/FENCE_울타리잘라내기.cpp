#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int solve(int left, int right) {
    // 기저 사례 : 판자가 하나밖에 없는 경우
    if(left==right) return v[left];

    // [left, mid], [mid+1, rihgt]의 두 구간으로 문제를 분할
    int mid = (left+right) / 2;
    // 분할한 문제를 각개격파
    int ret = max(solve(left, mid), solve(mid+1, right));

    // 부분 문제 3 : 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    int lo = mid, hi = mid+1;
    int height = min(v[lo], v[hi]);

    // [mid, mid+1]만 포함하는 너비 2인 사각형을 고려한다.
    ret = max(ret, height * 2);

    // 사각형이 입력 전체를 덮을 때까지 확장해 나간다.
    while(left < lo || hi < right) {
        // 항상 높이가 더 높은 쪽으로 확장
        if(hi < right && (lo==left || v[lo-1] < v[hi+1])) {
            ++hi;
            height = min(height, v[hi]);
        }
        else {
            --lo;
            height = min(height, v[lo]);
        }
        // 확장한 후 사각형의 넓이
        ret = max(ret, height * (hi-lo+1));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        v.resize(n);
        
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }

        cout << solve(0, n-1) << "\n";
    }

    return 0;
}