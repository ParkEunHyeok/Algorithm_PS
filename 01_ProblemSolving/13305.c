#include <stdio.h>

int main() {
    long long arr[101010];
    long long n, liter, prev=1000000000, money=0;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n-1; i++) 
    {
        scanf("%d", &liter);
        if(prev > liter) prev = liter;
        money += prev * arr[i];
    }

    printf("%lld", money);
    return 0;
}