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


struct Sparse{
  
    vector<vector<ll>> arr;
    vector<int> floor_log;

    //chamar build_table_log na main
    ll op(ll& a, ll& b){
        return min(a,b);
        //return max(a,b);
        //return __gcd(a,b);
    }
 
    void build_table_log(int MAXN){
        floor_log.resize(MAXN);
        floor_log[1] = 0;
        for(int i = 2; i < MAXN; i++)
            floor_log[i] = floor_log[i/2]+1;
    }

    Sparse(vector<ll>& v){ //Constrói a tabela
        int n = v.size(), logn = 0;
        while((1<<logn) <= n) logn++;
        build_table_log(n + 10);
        arr.assign(n, vector<ll>(logn, 0));
        for(int i = 0; i < n; i++)
            arr[i][0] = v[i];
        for(int k = 1; k < logn; k++){
            for(int i = 0; i < n; i++){
                if(i + ( 1 << k) -1 >= n)
                    break;
                int p = i+( 1 << (k-1) );                
                /*fazendo o intervalo usando a linha de cima da tabela,
                [i, 2^k-1] -> [i, 2^(k-1)-1] + [i+2^(k-1), 2^(k-1)-1  ].
                Por exemplo, o intervalo XXXX pode ser escrito como a operação
                em  (XXX)X e X(XXX)*. Existe intercessão.*/
                arr[i][k] = op( arr[i][ k-1 ] , arr[p][k-1]  );
            }
        }
    }

    ll query(int l, int r){
        int pot = floor_log[r-l+1];
        int k = (1 << pot) ;      
        return op(  arr[l][pot] , arr[  r - (k-1)  ][pot]   );
    }  
 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
