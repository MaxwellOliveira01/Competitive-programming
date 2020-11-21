#include <bits/stdc++.h>
using namespace std;
int comp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        if(a.first%2!=0 && b.first%2==0) return 1;
        if(a.first%2!=0 && b.first%2!=0) return a.first > b.first;
        if(a.first%2==0 && b.first%2==0) return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n,m,a;
    while(cin >> n >> m, n || m){
        vector< pair<int,int> > num;
        for(int j = 0; j < n; j++){
            cin >> a;
            num.push_back(make_pair(a,a%m));
        }
        sort(num.begin(),num.end(),comp);
        cout << n << " " << m << endl;
        for(int x = 0; x < num.size(); x++) cout << num[x].first << endl;
    }
    cout << m << " " << n << endl;
}
