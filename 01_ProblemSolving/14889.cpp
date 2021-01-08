#include <iostream>
#include <vector>
using namespace std;

int n, result=987654321;
int arr[22][22];
vector<int> start, link;

void dfs(int index) {
    if(index==n) {
        if(start.size()==n/2 && link.size()==n/2) {
            int start_sum = 0;
            int link_sum = 0;

            for(int i=0; i<n/2; i++) {
                for(int j=i+1; j<n/2; j++) {
                    start_sum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
                    link_sum += arr[link[i]][link[j]] + arr[link[j]][link[i]];                    
                }
            }

            result=min(result,abs(start_sum-link_sum));
        }
        return;
    }

    start.push_back(index);
    dfs(index+1);
    start.pop_back();

    link.push_back(index);
    dfs(index+1);
    link.pop_back();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0);

    printf("%d", result);
    return 0;
}