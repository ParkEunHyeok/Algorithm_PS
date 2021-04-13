#include <iostream>
#include <algorithm>
#include <vector>
int N;
using namespace std;
vector<int> v[1010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    
}
