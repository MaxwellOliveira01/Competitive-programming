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
  
    //inteiro mesmo?
    vector<vector<int>> arr;

    int op(int& a, int& b){ //min, max, gcd, lcm, and, or
        return min(a,b);
        //return __gcd(a,b);
        //return max(a,b);
    }

    Sparse(vector<int>& v){ //Constrói a tabela
        int n = v.size(), logn = 0;
        while((1<<logn) <= n) logn++;
        arr.assign(n, vector<int>(logn, 0));
        for(int i = 0; i < n; i++)
            arr[i][0] = v[i];
        for(int k = 1; k < logn; k++){
            for(int i = 0; i < n; i++){
                if(i + ( 1 << k) -1 >= n)
                    break;
                int p = i+( 1 << (k-1) );                
                arr[i][k] = op( arr[i][ k-1 ] , arr[p][k-1]  );
            }
        }
    }

    int query(int l, int r){
        int pot = 31 - __builtin_clz(r-l+1); //r-l+1 são INTEIROS, não ll
        int k = (1 << pot) ;      
        return op(  arr[l][pot] , arr[  r - (k-1)  ][pot]   );
    }   
 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    Sparse sp(arr);
    for(int i = 0; i < q; i++){
        int l, r; 
        cin >> l >> r;
        l--; r--;
        cout << sp.query(l, r) << "\n";
    }

}
