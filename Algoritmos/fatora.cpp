#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] "
#define ff first
#define ss second

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;

const int INF = 1e9; // INF to INT
//const ll INF = 1e18; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/

/*Published on
https://github.com/MaxwellOliveira01/Competitive-programming/tree/master/Algoritmos
*/

vector< pair<int,int> > fatora(ll n){
    vector< pair<int,int> > fat;

    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            int p = 0;
            while(n % i == 0){
                n /= i;
                p++;
            }
            fat.push_back(make_pair(i,p));
        }
    }
    if(n > 1) fat.push_back(make_pair(n, 1));
    return fat;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
