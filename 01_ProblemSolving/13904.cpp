#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 0;
    int deadline[1002] = {0,};
    vector<pii> v;
    cin >> n;

    while(n--) {
        int score, day;
        cin >> day >> score;
        v.push_back(make_pair(score, day));
    }
    sort(v.begin(), v.end(), greater<pii>());

    for(int i=0; i<v.size(); i++) {
        int score = v[i].first;
        int day = v[i].second;

        for(int j=day; j>0; j--) {
            if(deadline[j]==0) {
                deadline[j] = 1;
                result += score;
                break;
            }
        }
    }

    cout << result;
    return 0;
}