#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] "
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

const int oo = (int)1e9; //INF to INT
const ll OO = 0x3f3f3f3f3f3f3f3fLL; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/

ll knapsack(vector<int>& E, vector<int>& C, int sz){
    //E and C are 1-based for index.

    int n = (int)E.size()-1;
    vector< vector<ll> > dp(n+5, vector<ll>(sz+5));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sz; j++){
            if(C[i] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-C[i]]+E[i]);
            }
        }
    }
    return dp[n][sz];
}

vector<int> knapsack_path(vector<int>& E, vector<int>& C, int sz){

    //E and C are 1-based for index.

    int n = (int)E.size()-1;

    vector<int> path;
    vector< vector<pii > > go(n+5, vector<pii>(sz+5, {-1,-1}));
    vector< vector<ll> > dp(n+5, vector<ll>(sz+5));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sz; j++){
            if(C[i] > j){
                dp[i][j] = dp[i-1][j];
                go[i][j] = go[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-C[i]]+E[i]);
                if(dp[i-1][j] > dp[i-1][j-C[i]]+E[i]){
                    go[i][j] = go[i-1][j];
                } else {
                    go[i][j] = {i-1,j-C[i]};
                }
            }
        }
    }

    pii pq = {n,sz};
    while(pq.ff != -1 || pq.ss != -1){
        pq = go[pq.ff][pq.ss];
        path.push_back(pq.ff + 1); //indice
    }
    path.pop_back();

    return path;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> E(n+1), C(n+1); //Energia ganha / custo
 
    for(int i = 1; i <= n; i++){
        cin >> C[i] >> E[i];
    }

    auto ans = knapsack_path(E,C,t);
    cout << (int)ans.size() << "\n";
    for(auto v : ans)
        cout << v << " ";
    cout << "\n";
}
