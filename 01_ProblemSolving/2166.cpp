#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

int main() {
    int n;
    vector<pair<int, int> > v;

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {x,y};
    }

    double ans = 0;

    for(int i=1; i<n-1; i++) {
        double x1 = v[0].first;
        double x2 = v[i].first;
        double x3 = v[i+1].first;
        double y1 = v[0].second;
        double y2 = v[i].second;
        double y3 = v[i+1].second;

        ans += ((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3));
    }

    printf("%.1lf", abs(ans)/2);
    return 0;
}