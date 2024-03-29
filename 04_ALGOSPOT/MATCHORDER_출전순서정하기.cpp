#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> russian, korean;

int order() {
    int n = russian.size(), wins = 0;
    // 아직 남아 있는 선수들의 레이팅
    multiset<int> ratings(korean.begin(), korean.end());
    for(int rus=0; rus<n; ++rus) {
        // 가장 레이팅이 높은 한국 선수가 이길 수 없는 경우
        // 가장 레이팅이 낮은 선수와 경기시킨다.
        if(*ratings.rbegin() < russian[rus])
            ratings.erase(ratings.begin());
        // 이 외의 경우 이길 수 있는 선수 중 가장 레이팅이 낮은 선수와 경기시킨다.
        else {
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }

    return wins;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        russian.resize(n);
        korean.resize(n);
        for(int i=0; i<n; i++) cin >> russian[i];
        for(int i=0; i<n; i++) cin >> korean[i];

        cout << order() << "\n";
    }

    return 0;
}