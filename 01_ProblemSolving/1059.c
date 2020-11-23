#include <stdio.h>

int main() {
    //값 입력받기
    int arr[1001] = {0,};
    int l,n;
    scanf("%d\n", &l);
    for(int i=0; i<l; i++) {
        int number;
        scanf("%d ", &number);
        arr[number] = number;
    }
    scanf("%d",&n);

    // N이 LuckyNumber일 경우, 0출력
    if(arr[n]!=0) {
        printf("0");
        return 0;
    }

    // N이 들어간 Unlucky 구간의 최대 최소 구하기
    int min_num, max_num;
    for(int i=0; i<1000; i++) {
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

    int count = 0;

    // N+1==max_num이라면,
    if(arr[n+1]==max_num) {
        count = max_num - min_num - 1;
        printf("%d", count);
        return 0;
    }

    // Unlucky 구간의 개수 구하기
    for(int i=n; i>min_num; i--) {
        for(int j=i+1; j<max_num; j++) {
            count ++;
        }
    }

    printf("%d", count);
    return 0;
}
