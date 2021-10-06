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

struct Point{
    int x, y;
    
    Point(int xx = 0, int yy = 0){
        x = xx;
        y = yy;
    }

    Point operator+(Point& b){
        return Point(x+b.x,y+b.y);
    }

    Point operator-(Point& b){
        return Point(x-b.x,y-b.y);
    }

    int operator^(Point& b){ //cross
        return x * b.y - y * b.x;
    }
};

//reta a->b, c tá onde? 1 = esq, 0 = colinear, -1 = dir
int esq(Point& a, Point& b, Point& c){ 
    auto ansa = (b-a);
    auto ansb = (c-a);
    int ans = ansa^ansb;
    return ans >= 0;
}

//verifica se o ponto a tá dentro (ou na borda) do polígono
//arr tá com os pontos "ordenados"(cada ponto i e ponto i+1 são uma reta do polígono).
int inside(vector<Point> arr, Point& a){
    arr.push_back(arr[0]);
    for(int i = 0; i < (int)arr.size() - 1; i++){
        if(!esq(arr[i],arr[i+1],a)){
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d, m;
    cin >> n >> d >> m;
    vector<Point> arr = { Point(d, 0), Point(n, n-d), Point(n-d, n), Point(0, d)  };

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        Point p(x,y);
        if(inside(arr, p)){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}
