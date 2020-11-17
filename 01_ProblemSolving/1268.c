#include <stdio.h>

int main() {
    int n;
    int arr[1001][5];
    int student[1001] = {0,};
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
       for(int j=i+1; j<n; j++) {
           for(int k=0; k<5; k++) {
               if(arr[i][k] == arr[j][k]) {
                   student[i]++;
                   student[j]++;
                   break;
               }
           }
       }
   }

   int max = 0;
   int max_student_index = 1;
   for(int i=0; i<n; i++) {
       if(student[i]==0) continue;
       if(student[i] > max) {
           max = student[i];
           max_student_index = i+1;
       }
   }

   printf("%d", max_student_index);

   return 0;
}