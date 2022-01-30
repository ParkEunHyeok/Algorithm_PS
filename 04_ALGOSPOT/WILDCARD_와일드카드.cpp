#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string w, s;
int cache[102][102];

// -1 : 아직 확인 안함
// 0 : 매칭 불가능
// 1 : 매칭 가능
bool match(int a, int b) {
    int& ret = cache[a][b];
    if(ret!=-1) return ret;

    // w[a]와 s[b]를 맞춰나간다.
    while(a<w.size() && b<s.size() && (w[a]=='?' || w[a]==s[b])) {
        return ret = match(a+1, b+1);
    }

    // 패턴 끝에 도달했다면, 문자열도 끝에 도달했어야 함.
    if(a==w.size()) return ret = (b==s.size());

    // 와일드카드를 만났을 때, 몇 글자를 대응해야할 지 재귀호출하면서 끝냄.
    if(w[a]=='*') {
        // 매 단계에서 더 이상 대응시키지 않을건지 or 한 글자 더 대응시킬 건지
        if(match(a+1, b) || (b<s.size() && match(a, b+1))) {
            return ret = 1;
        }
    }

    // 이외의 경우에는 모두 대응되지 않음.
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while(c--) {
        int n;
        vector<string> res;

        cin >> w >> n;
        for(int i=0; i<n; i++) {
            cin >> s;

            memset(cache, -1, sizeof(cache));
            if(match(0,0)) res.push_back(s);
        }

        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) {
            cout << res[i] << "\n";
        }
    }

    return 0;
}