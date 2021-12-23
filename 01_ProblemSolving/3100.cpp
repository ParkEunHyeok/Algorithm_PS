#include <iostream>
using namespace std;

int main() {
    char arr[6][9];
    int result1 = 0, result2 = 0;

    for(int i=0; i<6; i++) {
        string tmp;
        cin >> tmp;

        for(int j=0; j<9; j++) {
            tmp[j] = arr[i][j];
        }
    }

    // 가로 삼등분
    int arr1[3][30] = {0,};
    int mx1 = 0, mx2 = 0, mx3 = 0;
    int mx1_idx, mx2_idx, mx3_idx;

    for(int i=0; i<2; i++) {
        for(int j=0; j<9; j++) {
            arr1[0][arr[i][j]-'A']++;

            if(mx1 < arr1[0][arr[i][j]-'A']) {
                mx1 = arr1[0][arr[i][j]-'A'];
                mx1_idx = arr[i][j]-'A';
            }
        }
    }
    for(int i=2; i<4; i++) {
        for(int j=0; j<9; j++) {
            arr1[1][arr[i][j]-'A']++;

            if(mx2 < arr1[0][arr[i][j]-'A']) {
                mx2 = arr1[0][arr[i][j]-'A'];
                mx2_idx = arr[i][j]-'A';
            }
        }
    }
    for(int i=4; i<6; i++) {
        for(int j=0; j<9; j++) {
            arr1[2][arr[i][j]-'A']++;

            if(mx3 < arr1[0][arr[i][j]-'A']) {
                mx3 = arr1[0][arr[i][j]-'A'];
                mx3_idx = arr[i][j]-'A';
            }
        }
    }

    if(mx1_idx!=mx2_idx && mx2_idx!=mx3_idx) {
        result1 += 18 - mx1;
        result1 += 18 - mx2;
        result1 += 18 - mx3;
    } else {
        if(mx1_idx==mx2_idx && mx2_idx==mx3_idx) {
            arr1[1][mx2_idx] = 0;
            mx2 = 0;

            for(int i=0; i<30; i++) {
                if(mx2 < arr1[0][i]) {
                    mx2 = arr1[0][i];
                    mx2_idx = i;
                }
            }
        } else {
            if(mx1_idx==mx2_idx) {
                
            }
        }
    }



}