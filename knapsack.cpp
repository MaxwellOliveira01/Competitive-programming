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

//Submeter em c++ 64bits otimiza o long long
ll knapsack(vector<ll>& weight, vector<ll>& value, int W) {
    //Usar essa knapsack se só precisar do resultado final.
    //O(W) em memória
    vector<vector<ll>> table(2, vector<ll>(W + 1, 0));
    int n = (int)value.size();

    for(int k = 1; k <= n; k++) {
        for(int i = 0; i <= W; i++) {
            if(i - weight[k - 1] >= 0) {
                table[k % 2][i] = max(table[ (k - 1) % 2 ][i], 
                    value[k - 1] + table[(k - 1) % 2][i - weight[k - 1]]); 
            } else {
                table[k % 2][i] = max(table[(k - 1) % 2][i], table[k % 2][i]);
            }
        }
    }

    return table[n % 2][W];
}

ll knapsack(vector<ll>& weight, vector<ll>& value, int W) {
    //Usar essa knapsack se, em algum momento, precisar recuperar os indices
    //O(NW) em memória

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

    return table[W][n];
}

const int MOD = 998244353;

struct Knapsack {

    int S; // max value
    vector<ll> dp;

    Knapsack(int S_) {
        S = S_ + 5;
        dp.assign(S, 0);
        dp[0] = 1;
    }

    void Add(int val) {
        if(val <= 0 || val >= S) return;
        for(int i = S - 1; i >= val; i--) {
            dp[i] += dp[i - val];
            dp[i] %= MOD;
        }
    }

    void Rem(int val) {
        if(val <= 0 || val >= S) return;
        for(int i = val; i < S; i++) {
            dp[i] += MOD - dp[i - val];
            dp[i] %= MOD;   
        }
    }

    int Query(int val) {
        // # of ways to select a subset of numbers with sum = val
        if(val <= 0 || val >= S) return 0;
        return dp[val];
    }

};


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
