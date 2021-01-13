#include <stdio.h>

int n, m;
int arr[102]={0,};
int fin[3];
int max=0; 

void brute(int cnt, int num) {
    if(cnt==3) {
        int sum=0;
        for(int i=0; i<3; i++) {
            sum += fin[i];
        }
        if(max<sum && sum<=m) max = sum;
        return;
    }    

    for(int i=num; i<n; i++) {
        fin[cnt] = arr[i];
        brute(cnt+1, i+1);
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    brute(0, 0);
    printf("%d", max);
    return 0;
}