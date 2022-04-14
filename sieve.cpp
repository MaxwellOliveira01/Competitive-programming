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

vector<int> sieve(int MAXN){
    //list of prime numbers up to MAXN
    vector<int> primes;
    bitset<(int)1e7> not_prime;
    not_prime[0] = 1;
    not_prime[1] = 1;
    for(int i = 2; i <= MAXN; i++){
        if(!not_prime[i]){
            primes.push_back(i);
            for(ll j = 1LL * i * i; j <= MAXN; j += i){
                not_prime[(int)j] = 1;
            }
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
