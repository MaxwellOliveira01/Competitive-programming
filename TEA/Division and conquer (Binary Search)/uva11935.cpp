#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const double eps = 1e-5;

vector< pair<int, pii> >eventos; // (distancia,(evento,quant))

//Fuel - > 0, leak -> 1, gas -> 2, mechanic -> 3, goal -> 4

int simula(double com){
    int evento,leakQ = 0; double comT=com,gasto,n,dist;
    n = eventos[0].ss.ss;
    for(int i = 1; i < eventos.size(); i++){
        evento = eventos[i].ss.ff;
        dist = eventos[i].ff - eventos[i-1].ff;


        comT-=dist*leakQ;

        if(dist*n/100 > comT) return 0;
        else {
            comT -= dist*n/100;
        }

        if(evento == 0) n = eventos[i].ss.ss;
        else if(evento == 1) leakQ++;
        else if(evento == 2) comT = com;
        else leakQ = 0;

    }
    return 1;
}

void busca(){
    double l = 0 , r = 10000,ans,m;
    while(abs(r-l) > eps){
        m = (l+r)/2;
        if(simula(m)){
            ans = m;
            r = m;
        }
        else l = m;
    }
    printf("%.3f\n",ans);
}

int main() {
    int a,b; string op,t;
    while(1){
        cin >> a >> op;
        if(op == "Fuel"){
            cin >> op >> b;
            if(!b) break;
            eventos.push_back({a,{0,b}});
        }
        else {
            if(op == "Gas"){
                cin >> op; //pegar o "Station"
                eventos.push_back({a,{2,-1}});
            }
            else if(op == "Goal"){
                eventos.push_back({a,{4,-1}});
                busca();
                eventos.clear();
            }
            else if(op == "Leak") eventos.push_back({a,{1,-1}});
            else eventos.push_back({a,{3,-1}});
        }
    }
}
