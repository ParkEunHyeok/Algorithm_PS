#include <stdio.h>

int main() {
    int meter, people;
    scanf("%d %d\n",&meter, &people);
    int answer = meter * people;

    for(int i=0; i<5; i++) {
        int expected;
        scanf("%d", &expected);
        printf("%d ", expected - answer);
    }
    return 0;
}