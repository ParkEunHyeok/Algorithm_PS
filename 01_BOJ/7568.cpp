#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<pair<int, int> > v;
    int prize = 1;

    cin >> n;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    for(int i=0; i<n; i++) {
        int prize = 1;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(v[i].first<v[j].first && v[i].second<v[j].second) {
                prize++;
            }
        }
        printf("%d ", prize);
    }

    return 0;
}