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

const int INF = 1e9; // INF to INT
//const ll INF = 1e18; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //gerar int
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); //gerar ll

    /*usar rng() pra gerar numeros aleatórios.*/
    /*usar rng() % x pra gerar numeros em [0, x-1]*/
    for(int i = 0; i < 10; i++){
        cout << rng() << endl;
    }
    vector<ll> arr = {1,2,3,4,5,6,7,8,9};
    /*dá pra usar no shuffle de vector também*/
    shuffle(arr.begin(), arr.end(),rng);
    for(auto &x: arr) 
        cout << x << endl;

}
