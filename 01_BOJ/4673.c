#include <stdio.h>

int arr[10002];

void self_num(int num) {
    int next = num;
    while(1) {
        if(num/10==0) {
            next += num;
            break;
        }
        else {
            next += num%10;
            num /= 10;
        }
    }

    if(next > 10000) return;

    arr[next] = 1;
    self_num(next);
}

int main() {
    for(int i=1; i<=10000; i++) {
        if(arr[i]==0) self_num(i);
    }

    for(int i=1; i<=10000; i++) {
        if(arr[i]==0) printf("%d\n", i);
    }

    return 0;
}