#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10], result[10];
bool visited[10];

void func(int l, int idx) {
    if(l==m) {
        for(int i=0; i<m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for(int i=idx; i<n; i++) {
        if(!visited[i] && arr[i]!=prev) {
            visited[i] = true;
            result[l] = arr[i];
            prev = arr[i];

            func(l+1, i);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    func(0,0);
    return 0;
}