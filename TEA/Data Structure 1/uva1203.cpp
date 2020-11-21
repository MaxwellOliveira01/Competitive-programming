#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;

map<int,int> valInicio;
vector<pii> arr;

int comp(pii a, pii b){
    if(a.ss > b.ss) return 0;
    if(a.ss < b.ss) return 1;
    return a.ff < b.ff;
}

int main() {
    string regis;
    int qid,period;
    while(cin >> regis, regis != "#"){
        cin >> qid >> period;
        valInicio[qid] = period;
        arr.push_back(make_pair(qid,period));
    }
    int k; cin >> k;
    sort(arr.begin(),arr.end(),comp);
    while(k!=0){
        cout << arr[0].ff << endl;
        arr[0].ss += valInicio[arr[0].ff];
        sort(arr.begin(),arr.end(),comp);
        k--;
    }
}
