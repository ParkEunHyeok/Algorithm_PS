#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    vector<int> arr;
    vector<int> v;

    cin >> n;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        arr.push_back(num);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        int cur = arr[i];
        int prev = 987654321;
        int a = 0;

        for(int j=0; j<n; j++) {
            if(cur > v[j]) {
                if(v[j]==prev) continue;
                a++;
                prev = v[j];
            }   
            else break;
        }

        cout << a << " ";
    }

    return 0;
}