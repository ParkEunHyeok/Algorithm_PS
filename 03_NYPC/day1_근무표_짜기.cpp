#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> w;
vector<int> res[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 개발자 수, 근무하는 날 수
    int n, m;
    cin >> n >> m;   

    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        pq.push({tmp, i});
    }

    for(int i=1; i<=m; i++) {
        int tmp;
        cin >> tmp;
        w.push_back({tmp, i});
    }

    while(!pq.empty()) {
        int day = pq.top().first;
        int person = pq.top().second;
        pq.pop();

        sort(w.begin(), w.end(), greater<pair<int, int> >());
        for(int i=0; i<m; i++) {
            int curSpace = w[i].first;
            int curIdx = w[i].second;
            if(day==0) break;

            if(curSpace>0) {
                curSpace--;
                day--;
                res[curIdx].push_back(person);
            }

            w[i].first = curSpace;
        }
    }

    for(int i=1; i<=m; i++) {
        cout << res[i].size() << " ";
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}