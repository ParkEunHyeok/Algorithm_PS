#include <iostream>
using namespace std;

int n;
int arr[15];
int lotto[6];

void dfs(int arr_idx, int lotto_idx) {
    if(lotto_idx==6) {
        for(int i=0; i<6; i++) {
            printf("%d ", lotto[i]);
        }
        printf("\n");
        return;
    }

    for(int i=arr_idx; i<n; i++) {
        lotto[lotto_idx] = arr[i];
        dfs(i+1, lotto_idx+1);
    }
}

int main() {
    while(1) {
        scanf("%d", &n);

        if(n==0) break;
        for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
        }

        dfs(0,0);
        printf("\n");
    }
    return 0;
}