#include <stdio.h>

int main() {
    int num, count = 1;
    scanf("%d", &num);
    int first_num = num;
    while(1) {
        int num_ten = num / 10;
        int num_one = num % 10;
        int num_sum = (num_ten + num_one) % 10;

        num = (num_one * 10) + num_sum;
        if(first_num == num) {
            printf("%d", count);
            break;
        }
        count++;
    }
    return 0;
}