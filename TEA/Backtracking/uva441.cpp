#include <bits/stdc++.h>
using namespace std;
int main() {
    int k,linha=0;
    while(cin >> k, k){
        int val[k];
        for(int i = 0; i < k; i++) cin >> val[i];
        if(linha) cout << endl;
        for(int a = 0; a < k-5; a++){
            for(int b = a+1; b < k-4; b++){
                for(int c = b+1; c < k-3; c++){
                    for(int d = c+1; d < k-2; d++){
                        for(int e = d+1; e < k-1; e++){
                            for(int f = e+1; f < k; f++){
                                cout << val[a] << " " << val[b] << " "<< val[c] << " "<< val[d]
                                << " " << val[e] << " " << val[f] << endl;
                            }
                        }
                    }
                }
            }
        }
        linha = 1;
    }
}
