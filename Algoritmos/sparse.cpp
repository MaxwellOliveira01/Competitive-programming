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

const int MAXN = 200000+1000; //valor grande tal que não precise de log de valores maiores
const int logn = 23;
int floor_log[MAXN+1];

/*Published on
https://github.com/MaxwellOliveira01/Competitive-programming/tree/master/Algoritmos
*/

void build_table_log(){
    /*Chamar essa função na main antes 
    de usar as queries da Sparse*/
    floor_log[1] = 0;
    for(int i = 2; i <= MAXN; i++)
        floor_log[i] = floor_log[i/2]+1;
}

struct Sparse{
  
    vector<vector<int>> arr;
    
    //chamar build_table_log na main
    int op(int& a, int& b){
        return min(a,b);
        //return max(a,b);
        //return __gcd(a,b);
    }
 
    Sparse(vector<int>& v){ //Constrói a tabela
        int n = v.size();
        arr.assign(n, vector<int>(logn, 0));
        
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

    int query(int l, int r){
        
        int pot = floor_log[r-l+1];
        int k = (1 << pot) ;
        
        return op(  arr[l][pot] , arr[  r - (k-1)  ][pot]   );
    }  
 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
