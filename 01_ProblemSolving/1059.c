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

    int max = 1004, min = 0;
    for(int i=0; i<1000; i++) {
        if(arr[i]==0) continue;
        else if(arr[i]==n) {
            printf("0");
            return 0;
        }
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }

    // 예외처리, N이 UnluckyNum의 최댓값보다 크거나 최솟값보다 작으면 0 출력
    if(n >= max || n <= min) {
        printf("0");
        return 0;
    }

    // N이 들어간 Unlucky 구간의 최대 최소 구하기
    int min_num=1004, max_num = 0;
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

    // Unlucky 구간의 개수 구하기
    int count = 0;
    
    if(min_num + 1 == n && n + 1 == max_num) {
        count = 0;
    }
    else if(max_num - n == 1) {
        count = n - (min_num + 1);
    }
    else
    {
        for(int i=n; i>min_num; i--) {
            for(int i=n; i<max_num-1; i++) {
                count++;
            }
        }
    }
    
    for(int i=(min_num+1); i<=n; i++) {
            count += (max_num-1)-i;
    }
    printf("%d", count);
    return 0;
}
