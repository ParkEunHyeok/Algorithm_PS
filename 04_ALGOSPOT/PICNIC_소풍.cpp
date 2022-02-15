#include <iostream>
#include <cstring>
using namespace std;

int n, m;
bool isFriend[12][12];

// taken[i] : i번째 학생이 이미 짝을 찾았으면 true, 아니면 fasle
int countParings(bool taken[12]) {
    // 남은 학생들 중 가장 빠른 인덱스
    int firstFree = -1;
    for(int i=0; i<n; i++) {
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }
    // 모든 학생이 짝을 찾은 경우
    if(firstFree==-1) return 1;

    int ret = 0;
    // 이 학생과 짝지을 핛애을 결정
    for(int pairWith = firstFree+1; pairWith<n; pairWith++) {
        if(!taken[pairWith] && isFriend[firstFree][pairWith]) {
            taken[pairWith] = taken[firstFree] = true;
            ret += countParings(taken);
            taken[pairWith] = taken[firstFree] = false;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        bool taken[12] = {0,};
        memset(isFriend, 0, sizeof(isFriend));

        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            isFriend[a][b] = 1;
            isFriend[b][a] = 1;
        }

        cout << countParings(taken) << "\n";
    }

    return 0;
}