#include <iostream>
#include <cstring>
using namespace std;

int first[100002];
int second[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        memset(first, 0, sizeof(first));
        memset(second, 0, sizeof(second));
        int first_max_idx=0, second_max_idx=0;
        cin >> n;
        
        for(int i=0; i<n; i++) {
            cin >> first[i] >> second[i];
            if(first[i]==1) first_max_idx = i;
            if(second[i]==1) second_max_idx = i;
        }

        int result = 0;
        for(int i=0; i<n; i++) {
            if(first[i]==1 || second[i]==1) result++;
            else if(first[i]<first[second_max_idx] && second[i]<second[first_max_idx]) {
                result ++;
            }
        }

        cout << result << "\n";
    }

    return 0;
}