#include <iostream>
#include <vector>
using namespace std;

int n, m, result;
vector<pair<int, int> > chicken, house;
bool visited[13];

int distance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void dfs(int idx, int selected) {
    if(selected==m) {
        int res = 0;
        for(int i=0; i<house.size(); i++) {
            int dist = 1987654321;
            for(int j=0; j<chicken.size(); j++) {
                if(visited[j]) {
                    dist = min(dist, distance(house[i], chicken[j]));
                }
            }
            res += dist;
        }

        result = min(result, res);
        return;
    }

    if(idx==chicken.size()) return;

    visited[idx] = true;
    dfs(idx+1, selected+1);
    visited[idx] = false;
    dfs(idx+1, selected);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tmp;

    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
    {
        cin >> tmp;
        if(tmp==1) {
            house.push_back({i,j});
        }
        else if(tmp==2) {
            chicken.push_back({i,j});
        }
    }

    result = 1987654321;
    dfs(0, 0);

    cout << result;
    return 0;
}