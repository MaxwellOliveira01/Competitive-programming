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

struct min_queue{
    stack< pair<ll,ll> > in, out;
 
    void add(ll x){
        if(in.size())
            in.push( { x,  min(x, in.top().ss)  } );
        else
            in.push( {x, x} );
    }
 
    ll get_min(){
        if(in.size() > 0 && out.size() > 0)
            return min(in.top().ss, out.top().ss);
        else if(in.size() > 0) return in.top().ss;
        else if(out.size() > 0) return out.top().ss;
        else return INF;
        
    }
 
    void rem(){
 
        if(out.size() == 0){
            while(in.size()){
                ll temp = in.top().ff,mi;
                if(out.size() == 0) mi = temp;
                else mi = min(temp, out.top().ss);
                out.push({temp, mi});
                in.pop();
            }
        }
        //removendo o topo de out
        out.pop();
    }
 
    ll sz(){
        return in.size() + out.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
