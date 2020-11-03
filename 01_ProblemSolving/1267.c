#include <stdio.h>

int main() {
    int n, arr[21];
    int Y_result=0, M_result=0;

    scanf("%d\n", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        
        Y_result += ((arr[i]/30) + 1) * 10;
        M_result += ((arr[i]/60) + 1) * 15;
    }

    if(Y_result > M_result) {
        // 민수 요금제 출력
        printf("M %d", M_result);
    }
    else if(M_result > Y_result) {
        // 영식 요금제 출력
        printf("Y %d", Y_result);
    }
    else {
        printf("Y M %d", Y_result);
    }

    return 0;
}