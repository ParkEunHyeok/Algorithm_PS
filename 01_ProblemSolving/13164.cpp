#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k, result=0;
    vector<int> v;
    vector<int> change;
    scanf("%d%d", &n, &k);
    v.resize(n);
    change.resize(n-1);
    
    cin >> v[0];
    for(int i=1; i<n; i++) {
        scanf("%d", &v[i]);
        int changing = v[i] - v[i-1];
        change.push_back(changing);
    }

    sort(change.begin(), change.end(), greater<int>());
    for(int i=k-1; i<change.size(); i++) {
        result += change[i];
    }

    printf("%d", result);
    return 0;
}