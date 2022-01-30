#include <stdio.h>

int main() {
    int n, m;
    int max = 1000000;
    int arr[1000001]={0,};
    arr[0]=1, arr[1]=1;

    // 에라토스테네스의 체
    for(int i=2; i<=max; i++) {
        if(arr[i]==1) continue;
        int weight=i;
        while(i+weight<=max) {
            weight+=i;
            arr[weight] = 1;
        }
    }

    scanf("%d%d", &n, &m);
    for(int i=n; i<=m; i++) {
        if(arr[i]==0) printf("%d\n",i);
    }

    return 0;
}