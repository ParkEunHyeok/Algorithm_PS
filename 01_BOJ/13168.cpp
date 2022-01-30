#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, r, m, v;   // 도시의 수, 내일로 티켓 가격, 여행할 도시의 수, 간선의 개수
map<string, int> capital;  
vector<string> travel;
float general[110][110];
float nailro[110][110];
#define INF 987654321

float smaller(float a, float b) {
    if(a > b) return b;
    else return a;
}

void floyd_warshall() { 
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                general[j][k] = smaller(general[j][k], general[j][i] + general[i][k]);
                nailro[j][k] = smaller(nailro[j][k], nailro[j][i] + nailro[i][k]);
            }
        }
    }
}

int main() {
    cin >> n >> r;
    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;
        capital[str] = i;
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        string str;
        cin >> str;
        travel.push_back(str);
    }   

    cin >> v;

    for(int i=0; i<102; i++) {
        for(int j=0; j<102; j++) {
            general[i][j] = nailro[i][j] = INF;
            if(i==j) general[i][j] = nailro[i][j] = 0;
        }
    }

    for(int i=1; i<=v; i++) {
        string vehicle, from, to;
        float cost;
        cin >> vehicle >> from >> to >> cost;
        
        general[capital[from]][capital[to]] = smaller(cost, general[capital[from]][capital[to]]);
        general[capital[to]][capital[from]] = smaller(cost, general[capital[to]][capital[from]]);

        // 내일로 무료
        if(vehicle=="ITX-Saemaeul" || vehicle=="ITX-Cheongchun" || vehicle=="Mugunghwa") {
            nailro[capital[from]][capital[to]] = 0;
            nailro[capital[to]][capital[from]] = 0;
        }
        // 내일로 -50%
        else if(vehicle=="S-Train" || vehicle=="V-Train") {
            nailro[capital[from]][capital[to]] = smaller(cost/2, nailro[capital[from]][capital[to]]);
            nailro[capital[to]][capital[from]] = smaller(cost/2, nailro[capital[to]][capital[from]]);
        }
        // 내일로 할인X
        else {
            nailro[capital[from]][capital[to]] = smaller(cost, nailro[capital[from]][capital[to]]);
            nailro[capital[to]][capital[from]] = smaller(cost, nailro[capital[to]][capital[from]]);
        }
    }

    floyd_warshall();

    float noilro_sum=0, nailro_sum=r;
    for(int i=0; i<travel.size()-1; i++) {
        noilro_sum += general[capital[travel[i]]][capital[travel[i+1]]];
        nailro_sum += nailro[capital[travel[i]]][capital[travel[i+1]]];
    }
    if(nailro_sum < noilro_sum) printf("Yes");
    else printf("No");
    return 0;
}