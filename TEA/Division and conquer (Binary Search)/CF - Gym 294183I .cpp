#include <bits/stdc++.h>
using namespace std;

double f(double a, double b, int c, double momento){
    return (a*b*c*exp(-b*momento))/pow((1+a*exp(-b*momento)),2);
}

int main() {
    int c; double a,b,momento,quant;
    cin >> c >> a >> b;

    if(a == 0) momento = 0;
    else momento = log(a)/b;

    quant = f(a,b,c,momento);

    printf("%.5f %.0f\n",momento,quant);

}
