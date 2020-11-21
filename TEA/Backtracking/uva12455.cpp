#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,p,soma=0,ans=0; cin >> t;
    vector<int> num(21,0);
    while(t--){
        cin >> n >> p;
        for(int i = 0; i < p; i++) cin >> num[i];

        for(int i = 0; i < (1<<p); i++){
            for(int j = 0; j < p; j++){
                if(i & (1 << j)) soma += num[j];
            }
            if(soma == n){
                ans = 1;
                break;
            }
            soma = 0;
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" <<  endl;

        soma = 0; ans = 0;
        num.clear();
    }
}
