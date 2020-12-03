#include <iostream>

using namespace std;

int many, n, count=0;
int map[101][101]={0,};
int visited[101]={0,};

void dfs(int v) {
    count++;
    visited[v] = 1;
    for(int i=1; i<=many; i++) {
        if(map[v][i]==1 && visited[i]==0) {
            dfs(i);
        }
    }
}

int main() {
    cin >> many >> n;
    for(int i=0; i<n; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        map[num1][num2] = 1;
        map[num2][num1] = 1;
    }
    dfs(1);

    cout << count-1;
    return 0;
}