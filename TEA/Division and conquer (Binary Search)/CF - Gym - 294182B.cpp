#include <bits/stdc++.h>
#define AnsMax 1e9
using namespace std;
int m,n,caixas[100010];

int test(int qDoces){
    int maes = m;
    for(int i = n-1; i >=0 && maes; i--){
        maes -= caixas[i]/qDoces;
        if(maes <= 0) return 1;
    }
    return 0;
}

int main() {
    int c,maxEle; cin >> n >> m;
    for(int i = 0; i < n; i++) scanf("%d",&caixas[i]);
    sort(caixas,caixas+n);
    int a=1,b=AnsMax,mid,ans=0,K;
    while(a <= b){
        mid = a+(b-a)/2;
        K = test(mid);

        if(K){
            a = mid+1;
            ans = mid;
        }
        else b = mid-1;

    }
    cout << ans << endl;
}
