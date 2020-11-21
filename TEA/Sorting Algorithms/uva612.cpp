#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>,string> i, pair<pair<int,int>,string> j){
    if(i.first.first < j.first.first) return 1;
    if(i.first.first == j.first.first){
        if(i.first.second < j.first.second) return 1;
    }
    return 0;
}

int bb_sort(string pala){
    //bubble sort
    int troca,cont=0;
    char aux;
    for(int f = pala.size(); f >= 0; f--){
        troca = 0;
        for(int c = 0; c < f-1; c++){
            if(pala[c] > pala[c+1]){
               aux = pala[c];
               pala[c] = pala[c+1];
               pala[c+1] = aux;
               troca = 1; cont ++;
            }
        }
        if(!troca) break;
    }
    return cont;
}

int main() {
    int M; cin >> M;
    for(int j = 0; j < M; j++){
        int tam,quant; cin >> tam >> quant;
        string re;
        vector<pair<pair<int,int>,string>> ans;
        for(int i = 0; i < quant; i++){
            cin >> re;
            ans.push_back(make_pair(make_pair(bb_sort(re),i),re));
        }
        sort(ans.begin(),ans.end(),comp);
        for(int i = 0; i < quant; i++){
            cout << ans[i].second << endl;
        }
        if(j != M-1) cout << endl;
    }
}
