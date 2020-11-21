#include <bits/stdc++.h>
using namespace std;
int row[8],linha = 1,x,y;

int verifica(int i, int c){
    for(int prev = 0; prev < c; prev++){
        if(row[prev] == i) return 0;
        if(abs(row[prev]-i) == abs(prev-c)) return 0;
    }
    return 1;
}

void solve(int c){
    if(c == 8 && row[y-1] == x-1){

        if(linha < 10) cout << " ";
        cout << linha++ << "      " << row[0]+1;
        for(int j = 1; j < 8; j++) cout << " " << row[j]+1;
        cout << endl;
        return;
    }

    for(int i = 0; i < 8; i++){
        if(verifica(i, c)) { //linha i rainha c
            row[c] = i; // rainha da linha c na col i
            solve(c+1);
        }
    }
}


int main() {
    int t; cin >> t;
    while(t--){
        cin >> x >> y;
        cout << "SOLN       COLUMN" << endl;
        cout <<  " #      1 2 3 4 5 6 7 8" << endl << endl;
        solve(0);

        if(t>0)cout << endl;
        memset(row,0,sizeof(row));
        linha=1;

    }
