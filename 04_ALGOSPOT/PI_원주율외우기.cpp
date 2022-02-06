#include <iostream>
#include <cstring>
using namespace std;
#define INF 1987654321

string str;
int cache[10002];

int classify(int a, int b) {
    string M = str.substr(a, b-a+1);

    // 첫 글자만으로 이루어진 문자열 : 난이도 1
    if(M==string(M.size(), M[0])) return 1;

    // 등차수열인지 검사
    bool progressive = true;
    for(int i=0; i<M.size()-1; i++) {
        if(M[i+1]-M[i] != M[1]-M[0])
            progressive = false;
    }
    // 등차수열의 공차가 1, -1이면 난이도는 2
    if(progressive && abs(M[1]-M[0])==1) return 2;

    // 두 수가 번갈아 등장하는지 확인
    bool alternating = true;
    for(int i=0; i<M.size(); i++) {
        if(M[i]!=M[i%2])
            alternating = false;
    }
    // 두 수가 번갈아 등장하면 난이도는 4
    if(alternating) return 4;
    // 공차가 +-1이 아닌 등차수열의 난이도는 5
    if(progressive) return 5;
    // 그 외 : 난이도 10
    return 10;
}

int memorize(int begin) {
    if(begin==str.size()) return 0;

    int& ret = cache[begin];
    if(ret!=-1) return ret;

    ret = INF;
    for(int i=3; i<=5; i++) {
        if(begin+i <= str.size()) {
            ret = min(ret, memorize(begin+i)+classify(begin, begin+i-1));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        memset(cache, -1, sizeof(cache));
        cout << memorize(0) << "\n";
    }

    return 0;
}