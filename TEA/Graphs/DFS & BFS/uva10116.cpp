#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
map<char,pii> posi;
int quantL,quantC;

int verifica(int i, int j){
    if(i >= 0 && j>=0 && i < quantL && j < quantC) return 1;
    return 0;
}

void solve(vector<string> mapa, int posiIni){
    vector< vector< int > > cont(quantL, vector<int>(quantC,0));
    cont[0][posiIni] = 1;
    int iAt=0,jAt=posiIni,i=0,j=posiIni;



    while(1){

        iAt += posi[ mapa[i][j] ].ff;
        jAt += posi[ mapa[i][j] ].ss;

        if(!verifica(iAt,jAt)) break;
        else if(cont[iAt][jAt] != 0) break;

        cont[iAt][jAt] = cont[i][j]+1;

        i = iAt;
        j = jAt;

    }

    if(!verifica(iAt,jAt))
        cout << cont[i][j] <<  " step(s) to exit" << endl;
    else
        cout << cont[iAt][jAt]-1 << " step(s) before a loop of " << cont[i][j]-cont[iAt][jAt]+1 << " step(s)" << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    posi['W'] = {0,-1};
    posi['S'] = {1,0};
    posi['E'] = {0,1};
    posi['N'] = {-1,0};

    int jIni;
    while(cin >> quantL >> quantC >> jIni, quantL || quantC || jIni){
        vector<string> mapa(quantL);
        for(int j = 0 ; j < quantL; j++) cin >> mapa[j];

        solve(mapa,jIni-1);

    }

}
