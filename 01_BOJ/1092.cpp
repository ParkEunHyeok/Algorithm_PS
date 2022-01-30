#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, num, time = 0;
    vector<int> crane, box;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num;
        crane.push_back(num);
    }
    sort(crane.begin(), crane.end(), greater<int>());

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> num;
        box.push_back(num);
    }
    sort(box.begin(), box.end(), greater<int>());

    if(crane[0] < box[0]) {
        cout << -1;
    }
    else {
        while(!box.empty()) {
            time++;

            for(int i=0; i<crane.size(); i++) {
                if(box.empty()) break;
                
                for(auto it = box.begin(); it!=box.end(); it++) {
                    if(*it <= crane[i]) {
                        box.erase(it);
                        break;
                    }
                }
            }
        }
        cout << time;
    }

    return 0;
}