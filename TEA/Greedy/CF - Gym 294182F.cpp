#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int comp(pii a, pii b){
    if(a.ff != b.ff) return a.ff < b.ff;
    //if(a.ss == b.ss) return 1;
    return a.ss > b.ss;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,a,b,c,ans=-1,m=0;
    char d,e;
    cin >> t;
    vector<pii> eventos;

    while(t--){
        cin >> a >> d >> b >> e >> c;
        eventos.push_back({c+b*60+a*60*60,1});

        //cout << a  << " " << b << " " << c << endl;

        cin >> a >> d >> b >> e >> c;
        eventos.push_back({c+b*60+a*60*60,-1});
    }

    sort(eventos.begin(),eventos.end(),comp);


    for(int x = 0; x < eventos.size(); x++){
        //cout << eventos[x].ff << " " << eventos[x].ss << endl;

        m += eventos[x].ss;
        ans = max(ans,m);
    }

    printf("%d\n",ans);

}
