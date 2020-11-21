#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define ff first
#define ss second
#define endl '\n'
using namespace std;

map<string,int> indice;
map<int,string> nomes;

int quantN;

void newComponent(stack<int>& S, int v, vector<int>& mark){
    vector<int> l;
    int w;

    do{
        w = S.top();
        S.pop();

        l.push_back(w);
        mark[w] = 2;

    } while(w != v);

    for(int i = 0; i < l.size()-1; i++)
        cout << nomes[l[i]] << ", ";
    cout << nomes[l.back()] << endl;

}

void scc(int v, stack<int>& S, int& n,vector<vi>& arr, vector<pii>& inf, vi& mark){
    inf[v].ff = n;
    inf[v].ss = n;

    n++;

    mark[v] = 1;
    S.push(v);

    for(auto w: arr[v]){

        if(mark[w] == 1)
            inf[v].ss = min(inf[v].ss,inf[w].ff);

        if(mark[w] == 0){
            scc(w,S,n,arr,inf,mark);
            inf[v].ss = min(inf[v].ss, inf[w].ss);
        }
    }

    if(inf[v].ff == inf[v].ss)
        newComponent(S,v, mark);

}

void findScc(vector<vi>& arr, vector<pii>& inf, vi& mark){
    stack<int> S;
    int n = 0;


    for(int i = 1; i <= quantN; i++)
        if(!mark[i])
            scc(i,S,n,arr,inf,mark);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m,dataSet = 1;
    string a,b;

    while(cin >> quantN >> m, quantN || m){

        vector< vi > arr(quantN+10, vi());
        vector< pii > inf(quantN+10); //ff -> index, ss -> low
        vector< int > mark(quantN+10,0);//0 -> nao visitado, 1 -> em processo, 2 -> finalizado

        indice.clear();
        nomes.clear();

        if(dataSet != 1) cout << endl;

        int posi = 1;

        for(int i = 0; i < m; i++){
            cin >> a >> b;

            if(!indice[a]){
                indice[a] = posi;
                nomes[posi] = a;
                posi++;
            }

            if(!indice[b]){
                indice[b] = posi;
                nomes[posi] = b;
                posi++;
            }

            arr[indice[a]].push_back(indice[b]);

        }

        cout << "Calling circles for data set " << dataSet++ << ":" << endl;
        findScc(arr,inf,mark);

    }
}
