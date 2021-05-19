#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    vector<int> force, speed, intellect;

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        force.push_back(tmp1);
        speed.push_back(tmp2);
        intellect.push_back(tmp3);
    }
    vector<int> v1(force);
    vector<int> v2(speed);
    vector<int> v3(intellect);

    sort(force.begin(), force.end());
    sort(speed.begin(), speed.end());
    sort(intellect.begin(), intellect.end());
    force.erase(unique(force.begin(), force.end()), force.end());
    speed.erase(unique(speed.begin(), speed.end()), speed.end());
    intellect.erase(unique(intellect.begin(), intellect.end()), intellect.end());


}