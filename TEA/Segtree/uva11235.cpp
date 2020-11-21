#include <bits/stdc++.h>
using namespace std;
map<int,int> quant;
int num[100100], inicio[100100],st[4*100100],n;

int esq(int x){ return 2*x; }
int dir(int x){ return 2*x+1; }
int meio(int a,int b){ return (a+b)/2; }

void visualiza(){
    for(int i = 1; i <= 4*n; i++) cout << st[i] << " ";
    cout << endl;
}

void montaSt(int x,int i, int j){
    if(i == j) st[x] = quant[num[i]];
    else{
        montaSt(esq(x),i,meio(i,j));
        montaSt(dir(x),meio(i,j)+1,j);
        st[x] = max(st[esq(x)],st[dir(x)]);
    }
}

int query(int x, int l, int r, int i, int j){
    if(l>j || r<i) return -1;
    else if(l>= i && r<=j) return st[x];
    int esquerda = query(esq(x),l,meio(l,r),i,j);
    int direita = query(dir(x),meio(l,r)+1,r,i,j);
    return max(esquerda,direita);
}

int main(){
    int q,a,b,c1,c2,c3;
    while(cin >> n, n!=0){

        //prepara pro próximo teste
        quant.clear();
        memset(num,0,sizeof(num)); memset(st,0,sizeof(st)); memset(inicio,0,sizeof(inicio));

        cin >> q;
        for(int i = 1; i <= n; i++){
            cin >> num[i];
            quant[num[i]]++;
            if(inicio[num[i]] == 0) inicio[num[i]] = i;
        }
        montaSt(1,1,n);

         while(q--){
            cin >> a >> b;
            if(num[a] == num[b]) cout << b-a+1 << endl;
            else{
                int teste = inicio[num[a]] + quant[num[a]]; ;
                c1 = teste-a;
                c2 = b-inicio[num[b]]+1;
                c3 = query(1,1,n,teste,inicio[num[b]]-1);
                cout << max(c1,max(c2,c3)) << endl;
            }
        }
    }
}
