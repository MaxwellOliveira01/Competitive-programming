#include <bits/stdc++.h>
using namespace std;
vector<int> val(100010);
vector<int> st(400025);
int n;
int esq(int x){ return x+x; }
int dir(int x){ return x+x+1; }
int meio(int i, int j){ return (i+j)/2; }

void montaSt(int x, int i, int j){
    if(i == j) st[x] = val[i];
    else{
        montaSt(esq(x),i,meio(i,j));
        montaSt(dir(x),meio(i,j)+1,j);
        st[x] = st[dir(x)]*st[esq(x)];
    }
}

void change(int x, int l, int r, int k, int value){
    if(l == r){
        if(value != 0) value = abs(value)/value;
        val[k] = value;
        st[x] = val[k];
    }
    else{
        if(k <= meio(l,r)) change(esq(x),l,meio(l,r),k,value);
        else change(dir(x),meio(l,r)+1,r,k,value);
        st[x] = st[esq(x)]*st[dir(x)];
    }
}

int prod(int x,int l,int r,int i,int j){
    if(i>r || j < l) return -100;
    else if(l >= i && r <= j) {
        return st[x];
    else{

        int prodEst = prod(esq(x),l,meio(l,r),i,j);
        int prodDir = prod(dir(x),meio(l,r)+1,r,i,j);

        if(prodDir == -100) return prodEst;
        if(prodEst == -100) return prodDir;

        return prodDir*prodEst;
    }
}


int main() {
    int k,a,b,re,ans; //[a,b]
    char com;
    while(scanf("%d %d",&n,&k) == 2){
        st.assign(4*n+10,0); val.assign(n,0);
        string teste = "";
        for(int i = 0; i < n; i++){
            cin >> re;
            if(re == 0 ) val[i] = 0;
            else re > 0 ? val[i] = 1 : val[i] = -1;
        }
        montaSt(1,0,n-1);
        while(k--){
            cin >> com >> a >> b;
            if(com == 'C') change(1,0,n-1,a-1,b); // a-1?
            else{
                ans = prod(1,0,n-1,a-1,b-1);
                if(ans == 0) teste+="0";
                else if(ans < 0) teste+="-";
                else teste+="+";
            }
        }
        cout << teste << endl;
    }
}
