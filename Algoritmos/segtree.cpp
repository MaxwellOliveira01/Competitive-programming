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

struct Segtree {

    int n; //size do array que a seg vai ser criada em cima
    vector<ll> seg;

    Segtree(vector<ll>& s){
        n = (int)s.size();
        seg.assign(n+n+n+n, 0);
        seg_build(1,0,n-1,s);
    }

    ll merge(ll a, ll b){
        return a+b;
    }

    void seg_build(int x, int l, int r, vector<ll>& s){
        if(r < l) return;
        if(l == r){
            seg[x] = s[l];
        } else {
            int mid = l + (r-l)/2;
            seg_build(x+x, l, mid, s);
            seg_build(x+x+1, mid+1, r, s);
            seg[x] = merge(seg[x+x], seg[x+x+1]);
        }
    }

    //nó atual, intervalo na árvore e intervalo pedido
    ll q(int x, int l, int r, int i, int j){
        if(r < i || l > j ) return 0;
        if(l >= i && r <= j ) return seg[x];

        int mid = l + (r-l)/2;

        ll esq = q(x+x,l,mid,i,j);
        ll dir = q(x+x+1,mid+1,r,i,j);
        
        if(esq == 0) return dir;
        else if(dir == 0) return esq;
        return merge(esq,dir);
    }

    //att posi pra val
    void att(int x, int l, int r, int posi, int val){
        if(l == r){
            seg[x] = val;
        } else {
            int mid = l + (r-l)/2;
        
            if(posi <= mid){
                att(x+x,l,mid,posi,val);    
            } else {
                att(x+x+1,mid+1,r,posi,val);
            } 

            seg[x] = merge(seg[x+x], seg[x+x+1]);
        }
    }
 
    ll query(int l, int r){
        return q(1, 0, n-1, l, r);
    }

    void update(int posi, int val){ //alterar em posi pra val
        att(1, 0, n-1, posi, val);
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
