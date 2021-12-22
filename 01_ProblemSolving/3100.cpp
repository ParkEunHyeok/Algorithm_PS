#include <iostream>
using namespace std;

int main() {
    char arr[6][9];

    for(int i=0; i<6; i++) {
        string tmp;
        cin >> tmp;

        for(int j=0; j<9; j++) {
            tmp[j] = arr[i][j];
        }
    }

    // 가로 삼등분
    int arr1[3][30] = {0,};

    for(int i=0; i<2; i++) {
        for(int j=0; j<9; j++) {
            arr1[0][arr[i][j]-'A']++;
        }
    }
    for(int i=2; i<4; i++) {
        for(int j=0; j<9; j++) {
            arr1[0][arr[i][j]-'A']++;
        }
    }
    for(int i=4; i<6; i++) {
        for(int j=0; j<9; j++) {
            arr1[0][arr[i][j]-'A']++;
        }
    }

    for(int i=4; i<6; i++) {
        for(int j=0; j<9; j++) {
            arr1[0][arr[i][j]-'A']++;
        }
    }
}