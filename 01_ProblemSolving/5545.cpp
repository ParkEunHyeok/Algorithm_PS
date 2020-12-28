#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, a, b;    // 토핑의 종류, 도우의 가격, 토핑의 가격
    int dou;
    vector<int> v;
    
    cin >> n;
    cin >> a >> b;
    cin >> dou;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    float max_calorie = dou/a;
    int sum_calorie = dou;
    int sum_kind = a;
    for(int i=0; i<n; i++) {
        float current_calorie;
        sum_calorie += v[i];
        sum_kind += b;
        current_calorie = sum_calorie / sum_kind;
        
        if(current_calorie >= max_calorie) {
            max_calorie = current_calorie;
        }
        else {
            break;
        }
    }

    printf("%.0f", max_calorie);
    return 0;
}