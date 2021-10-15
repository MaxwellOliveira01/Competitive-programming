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

//O(size(s))
ll stringModM(string& s, ll mod, ll base){
    //s is a number in base 'base'. This function returns this number in mod 'mod' in base 10.
    ll ans = 0;
    for(int i = 0; i < (int)s.size(); i++){
        ans *= base;
        ans += (s[i] - '0');
        ans %= mod;
    }
    return ans;
}

void solve(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    cout << (stringModM(s,n,2) == 0 ? "To the moon!\n" : "Phishing de criptomoeda.\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--)
        solve();

}
