#include <bits/stdc++.h>
using namespace std;
int score[105];
vector<int> candidato;
int erros[105][11]; int penalty[105];
int questoes[105][11];
map<int,int> marca;

int org(int a, int b){
    if(score[a] < score[b]) return 0;
    if(score[a] == score[b]){
        if(penalty[a] > penalty[b]) return 0;
        if(penalty[a] == penalty[b]) return a<b;
    }
    return 1;
}

void limpa(){
    candidato.clear();
    marca.clear();
    for(int i = 0; i < 105; i++){
        penalty[i] = 0; score[i] = 0;
        for(int j = 0; j < 11; j++) {
            erros[i][j] = 0;
            questoes[i][j] = 0;
        }
    }
}

int main() {
    int q; cin >> q;
    string ler;
    getline(cin,ler);
    getline(cin,ler);
    while(q--){
        int c,p,t; char l; string ler;
        while(getline(cin,ler), ler.size()>0){
            stringstream teste(ler);
            //cout << ler << endl;
            teste >> c >> p >> t >> l;
            if(l != 'C' && l != 'I'){
                if(!marca[c]) candidato.push_back(c);
                marca[c] = 1;
                continue;
            }
            if(l == 'C'){
                if(!questoes[c][p]){
                    score[c]++;
                    penalty[c] += 20*erros[c][p] + t;
                    questoes[c][p]=1;
                }

            }
            else erros[c][p]++;
            if(!marca[c]){
                candidato.push_back(c);
                marca[c] = 1;
            }
        }

        sort(candidato.begin(), candidato.end(), org);
        for(int i = 0; i < candidato.size(); i++){
            if(candidato[i] == 0) continue;
            cout << candidato[i] << " " << score[candidato[i]] << " " << penalty[candidato[i]] << endl;
        }
        if(q>0) cout << endl;
        limpa();
    }
}

