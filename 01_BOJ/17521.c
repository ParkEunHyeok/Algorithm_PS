#include <stdio.h>

int main() {
    long long day, money, coin=0;
    long long arr[16]={0,};
    scanf("%lld%lld", &day, &money);

    for(int i=1; i<=day; i++) {
        scanf("%lld", &arr[i]);
    }

    for(int i=1; i<day; i++) {
        if(arr[i] < arr[i+1]) {
            coin += money/arr[i];
            money %= arr[i]; 
        }
        else if(arr[i] > arr[i+1]) {
            money += coin * arr[i];
            coin = 0;
        }
    }
    money += coin * arr[day];

    printf("%lld", money);
    return 0;
}