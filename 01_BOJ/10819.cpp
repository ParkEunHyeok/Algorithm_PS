#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10];
bool selected[10];
int fin[10];
int result = 0;

void dfs(int cnt) {
    if(cnt==n) {
        int sum = 0;
        for(int i=0; i<n-1; i++) {
            sum += abs(fin[i]-fin[i+1]);
        }
        result = max(result, sum);
        return;
    }

    for(int i=0; i<n; i++) {
        if(selected[i]==false) {
            selected[i] = true;
            fin[cnt] = arr[i];
            dfs(cnt+1);
            selected[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    dfs(0);
    cout << result;
    return 0;
}