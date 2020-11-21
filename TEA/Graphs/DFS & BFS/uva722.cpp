#include <bits/stdc++.h>
using namespace std;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
int cont = 0,maxI,maxJ;

int verifica(int i, int j){
    return ( i>=0 && j>=0 && j < maxJ && i < maxI );
}

void solve(vector< string >& arr,int i, int j){

    if(arr[i][j] == '0'){
        cont++;
        arr[i][j] = '9';
    }

    for(int p = 0; p < 4; p++){
        int iAt = i+di[p], jAt = j+dj[p];

        if(!verifica(iAt,jAt)) continue;

        if(arr[iAt][jAt] == '0'){
            cont++;
            arr[iAt][jAt] = '9';
            solve(arr,iAt,jAt);
        }
    }

}

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        string ler;
        vector<string> arr;
        int posiI, posiJ;
        char teste;

        cin >> posiI >> posiJ;

        scanf("%c",&teste);
        while(getline(cin,ler), ler.size() > 0)
            arr.push_back(ler);

        maxJ = arr[0].size();
        maxI = arr.size();


        //for(auto x: arr) cout << x << endl;

        solve(arr,posiI-1,posiJ-1);

        cout << cont << endl;

        if(t != 0) cout << endl;
        cont = 0;

    }

}
