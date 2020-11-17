#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[1001][5];
    int student[1001] = {0,};
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", arr[i]);
    }
    /*
    for(int i=0; i<5; i++) {
        for(int j=0; arr[j][i]!=NULL; j++) {
            for(int k=j; arr[k][i]!=NULL; k++) {
                if(arr[j][i]==arr[k][i]) {
                    
                }
            }
        }
    }
    */

   for(int i=0; arr[i]!=NULL; i++) {
       for(int j=i+1; arr[j]!=NULL; j++) {
           for(int k=0; k<5; k++) {
               if(arr[i][k] == arr[j][k]) {
                   student[i]++;
                   student[j]++;
                   break;
               }
           }
       }
   }
}