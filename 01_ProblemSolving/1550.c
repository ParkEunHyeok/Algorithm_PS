#include <stdio.h>

int main() {
    char input[50];
    int result = 0;

    scanf("%s", input);

    for(int i=0; input[i]!=NULL; ++i) {
        result *= 16;

        if('0'<=input[i] && input[i]<='9') result += (input[i]-'0');
        else {
            result += (input[i]-'A'+10);
        }
    }

    printf("%d", result);
    
    return 0;
}