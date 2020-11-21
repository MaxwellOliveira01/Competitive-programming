#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int comp1(pii a, pii b){
    return a.ss < b.ss;
}

int comp2(vector<pii> a, vector<pii> b){
    //cout << a[0].ss << " " << b[0].ss << endl;
    return a[0].ss < b[0].ss;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c, s,caso=1;
    while(scanf("%d %d",&c,&s) == 2){
        //if(caso>1) cout << endl;
        cout << "Set #" << caso++ << endl;

        vector<pii> pesos(c+c,{0,2000});
        vector<vector<pii>> ans(c);

        long double sum = 0,im = 0;

        for(int i = 0; i < s; i++){
            scanf("%d",&pesos[i].ff);
            pesos[i].ss = i;
            sum += pesos[i].ff;
        }
        sum /= c;
        sort(pesos.begin(),pesos.end());

        for(int i = 0; i < c; i++){

            //if(pesos[i].ff)
            ans[i].push_back({pesos[i].ff,pesos[i].ss});

            //if(pesos[c+c-i-1].ff)
            ans[i].push_back({pesos[c+c-i-1].ff,pesos[c+c-i-1].ss});

            sort(ans[i].begin(),ans[i].end(),comp1);

            im += abs(sum-(pesos[i].ff+pesos[c+c-i-1].ff));
        }

        ans.resize(c);
        sort(ans.begin(),ans.end(),comp2);

        for(int i = 0; i < c; i++){
            cout << " " << i << ":";
            if(ans[i][0].ff) cout << " " << ans[i][0].ff;
            if(ans[i][1].ff) cout << " " << ans[i][1].ff;

            cout << endl;
        }


        cout.precision(5);
        cout.setf(ios::fixed);

        cout << "IMBALANCE = " << im << endl;
        cout << endl;

    }

}
