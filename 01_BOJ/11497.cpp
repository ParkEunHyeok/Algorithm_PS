#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, mx=0;
        vector<int> v;
        scanf("%d", &n);

        for(int j=0; j<n; j++) {
            int number;
            scanf("%d", &number);
            v.push_back(number);
        }
        sort(v.begin(), v.end());
        
        mx = max(mx, v[1] - v[0]);
        for(int j=2; j<n; j++) {
            mx = max(mx, v[j] - v[j-2]);    
        }

        printf("%d\n", mx);
    }

    return 0;
}