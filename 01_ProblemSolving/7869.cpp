#include <iostream>
#include <cmath>
using namespace std;

double pi = 3.14159265358979;

int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(r2 > r1) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    if(dist >= r1 + r2) {
        // 두 원이 겹치지 않음.
        cout << "0.000";
    }
    else if(dist + r2 <= r1) {
        // 작은 원이 내부에 있음.
        double s = pi * r2 * r2;
        printf("%.3f", s);
    }
    else {
        // 두 원이 일부 겹칠 때
        double theta1 = acos((r1*r1 + dist*dist - r2*r2) / (2 * r1 * dist));
        double theta2 = acos((r2*r2 + dist*dist - r1*r1) / (2 * r2 * dist));

        double s1 = (r1 * r1 * theta1) - ((r1*r1 * sin(theta1*2))/2);
        double s2 = (r2 * r2 * theta2) - ((r2*r2 * sin(theta2*2))/2);

        printf("%.3f", s1+s2);
    }

    return 0;
}