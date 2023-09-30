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

const int MOD = 1e9+7;
 
struct Mat{
    vector<vector<ll>> matriz;
    int l, c;
 
    Mat(vector<vector<ll>>& mat){
        matriz = mat;
        l = mat.size();
        c = mat[0].size();
    }
    
    Mat(int r, int col, bool identidade=false){ 
        //qnt linhas, qnt colunas, identidade
        l = r;  c = col;
        matriz.assign(l, vector<ll>(col, 0));
        if(identidade){
            for(int i = 0; i < min(l,col); i++)
                matriz[i][i] = 1;
        }
    }
 
    Mat operator * (const Mat& a) const{
        assert(c == a.l); //qnt lcolunas mat deve ser igual qnt linhas a
        vector<vector<ll>> resp(l, vector<ll>(a.c, 0));
        //multiplica. Algoritmo cúbico.
        for(int i = 0; i < l; i++){
            for(int j = 0; j < a.c; j++){
                for(int k = 0; k < a.l; k++){
                    resp[i][j] = (resp[i][j] + (matriz[i][k]*a.matriz[k][j]) % MOD) % MOD;
                }
            }
        }
        return Mat(resp);
    }
 
    Mat operator + (const Mat& a) const{
        assert(l == a.l && c == a.c); //dimensoes iguais
        vector<vector<ll>> resp(l, vector<ll>(c,0));
        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                resp[i][j] = (resp[i][j] + matriz[i][j] + a.matriz[i][j]) % MOD;
            }
        }
        return Mat(resp);
    }
};
 
Mat fexp(Mat& base, ll expoente, ll sz){
    Mat result = Mat(sz, sz, 1);
    while(expoente > 0){
        if(expoente & 1) result = result * base;
        base = base * base;
        expoente /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b;
    cin >> a >> b >> n;

    Mat X(2,2);
    
    //f_i = c1 * f_(i-1) + c2 * f(i-2) + ... + ck * f(i-k)
    // monta a matriz X
    //  A 2° diagonal (todas as posições acima dos elementos q pertecem a diagonal principal) = 1
    //  A ultima linha é composta por c_k, c_(k-1), c_(k-2), .... , c_2, c_1
    //Para se ter o p-ésimo elemento é só fazer X^(P-1) pq indexa em 0
    //e multiplicar pela matriz coluna, onde os elementos são: [f(0)
    /*                                                          f(1)
                                                                f(2)
                                                                ....
                                                                f(k-1)
                                                                ]
    */

    //nessa questão a gente tem que f_i = f_(i-1) - f(i-2), sendo que f_0 = a e f_1 = b, a matriz fica
    
    // 0 1
    //-1 1
    X.matriz[0][1] = 1;
    X.matriz[1][0] = -1;
    X.matriz[1][1] = 1;

    Mat y = fexp(X,n-1,2);

    ll ans = y.matriz[0][0] * a + y.matriz[0][1] * b;

    while(ans < 0)
        ans += MOD;

    cout << ans % MOD << endl;
}
