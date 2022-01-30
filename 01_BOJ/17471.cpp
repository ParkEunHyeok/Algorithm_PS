#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int city, entire;
int population[12];
vector<int> v[10];
bool visited[10];
int dfsSum;
int result = 987654321;

void diff() {
    int a = entire - dfsSum;
    int b = dfsSum;
    if(a>b) result = min(result, a-b);
    else result = min(result, b-a);
}

void dfs(int node){
    visited[node] = true;
    dfsSum += population[node];
    diff();

    for(int i=0; i<v[node].size(); i++) {
        if(!visited[v[node][i]]) {
            dfs(v[node][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> city;
    for(int i=0; i<city; i++) {
        int num;
        cin >> num;
        population[i] = num;
        entire += num;
    }
    for(int i=0; i<city; i++) {
        int num;
        cin >> num;
        v[i].resize(num);
        for(int j=0; j<num; j++) {
            cin >> v[i][j];
        }
    }

    for(int i=0; i<city; i++) {
        dfsSum = 0;
        dfs(i);
    }

    cout << result;
    return 0;
}