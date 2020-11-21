#include <bits/stdc++.h>
#define PI 3.141592653589793
using namespace std;

int main() {
    long double x1,y1,x2,y2,ang1,ang2,dist,t1,t2;
    while(cin >> x1 >> x2 >> y1 >> y2 >> ang1 >> ang2){

        t1 = tan(ang2*PI/180.0);
        t2 = tan(ang1*PI/180.0);

        dist = sqrt( (x1-y1)*(x1-y1) + (x2-y2)*(x2-y2) );

        //dist / t1 = NA e dist/t2 = MA
        printf("%.3Lf\n", dist/t1 + dist/t2);
    }
}
