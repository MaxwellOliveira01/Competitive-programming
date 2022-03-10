#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] ";
#define debugendl(x) cout << "[" << #x << " = " << x << "]\n";
#define ff first
#define ss second

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;

using tii = tuple<int,int,int>;
// auto [a,b,c] = ...
// .insert({a,b,c})

const int oo = (int)1e9 + 5; //INF to INT
const ll OO = 0x3f3f3f3f3f3f3f3fLL; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/

//table[idx][porcen] = menor tempo pra esse estado
//= min(
//  table[idx - 1][porcen]
//  table[idx][porcen - pi[i]] + ti[i]   )

const int MAXP = 150;

ll knapsack(vector<ll>& weight, vector<ll>& value, int W) {

    int n = (int)value.size();
    vector<vector<ll>> table(W + 1, vector<ll>(n + 1, 0));

    for(int k = 1; k <= n; k++) {
        for(int i = 0; i <= W; i++) {
            if(i - weight[k - 1] >= 0) {
                table[i][k] = max(table[i][k - 1], 
                    value[k - 1] + table[i - weight[k - 1]][k - 1]); 
            } else {
                table[i][k] = max(table[i][k - 1], table[i][k]);
            }
        }
    }

    /*
    int per = W;
    vector<int> idx;
    for(int k = n; k > 0; k--) {
        if(table[per][k] == table[per][k - 1]){
            continue;
        } else {
            idx.push_back(k - 1);
            per -= weight[k - 1];
        }
    }
    */

/*
    //knapsack "invertida" -> minimizar + nao contar 2x o mesmo item
    //separa os estados em 2 classes, por valor mesmo e por >= algo
    //tipo [0,99] e +1 representando >= 100
    int n = (int)value.size();
    vector<vector<ll>> table(W + 1, vector<ll>(n + 1, OO));
    table[0][0] = 0;
    for(int k = 1; k <= n; k++) {
        table[0][k] = 0;
        for(int i = W; i > 0; i--) {
            int prev =  max(0, i - weight[k - 1]);
            table[i][k] = min(table[i][k - 1], t[k - 1] + table[prev][k - 1]);
        }
    }
    int per = 100;
    vector<int> idx;
    for(int k = n; k > 0; k--) {
        if(table[per][k] == table[per][k - 1]){
            continue;
        } else {
            idx.push_back(k - 1);
            per = max<int>(0, per - weight[k - 1]);
        }
    }
*/
    return table[W][n];
}

void solve() {
    
    int n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    for(int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(weight, value, w) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

}