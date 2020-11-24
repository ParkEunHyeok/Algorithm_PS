#include <stdio.h>

int main() {
    // 값 입력받기
    int arr[1001] = {0,};
    int l, n, count=0;
    scanf("%d\n", &l);
    for(int i=0; i<l; i++) {
        int number;
        scanf("%d ", &number);
        arr[number] = number;
    }
    scanf("%d",&n);

    // 예외 : n이 LuckyNumber일 경우 -> 0
    if(arr[n]!=0) {
        printf("0");
        return 0;
    }

    // N이 들어간 Unlucky 구간의 최대 최소 구하기
    int min_num=0, max_num;
    for(int i=0; i<=1000; i++) {
        if(arr[i]==0) continue;
        else {
            if(arr[i] < n) {
                min_num = arr[i];
            }
            if(n < arr[i]) {
                max_num = arr[i];
                break;
            }
        }
    }

    // 공식 : (n-min_num-1)*(max_num-n)+(max_num-n-1)

    // Unlucky 구간의 개수 구하기
    for(int i=min_num+1; i<=n; i++) {
        for(int j=n; j<max_num; j++) {
            count++;
        }
    }
    count--;

    printf("%d", count);

    return 0;
}