#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
using namespace std;

map<int,char> toChar;
map<char,int> toIndex;
int exist = 0;

int check(vector<vi>& arr,int j, int p, vi& ans){

    //dado que p vem antes de j,
    //check verifica se p já está na solução

    for(auto x: ans)
        if(x == p)
            return 1;
    return 0;
}

int possible(vector<vi>& arr, int j, vi& ans){
    //tenta por J: Para isso há dois casos:
    //1: Não há ninguem que venha antes de J;
    //2: Todos que vem antes de J já apareceram
    for(int p = 0; p < arr[j].size(); p++)
        if(arr[j][p])
            if(!check(arr,j,p,ans))
                return 0;
    return 1;
}

void solve(vector<vi>& arr, vi& mark,vi& ans){
    if(ans.size() == mark.size()){
        for(int i = 0; i < ans.size()-1; i++)
            cout << toChar[ans[i]] << " ";
        cout << toChar[ans.back()] << endl;

        exist = 1;

        return;
    }

    for(int j = 0; j < mark.size(); j++){

        if(mark[j])
            continue;

        else if(possible(arr,j,ans)){
            mark[j] = 1;
            ans.push_back(j);

            solve(arr,mark,ans);

            ans.pop_back();
            mark[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t; cin >> t;
    string re;

    getline(cin,re);
    getline(cin,re);

    while(t--){

        getline(cin,re);

        int posi = 0;
        int tam = (re.size()+1)/2;


        vector<vi> arr(tam, vi( tam,0) );
        vi mark(tam,0);
        vi ans;


        for(int i = 0; i < re.size(); i+=2){
            toChar[posi] = re[i];
            toIndex[re[i]] = posi++;
        }

        getline(cin,re);

        for(int i = 0; i < re.size();i+=4)
            arr[toIndex[re[i+2]]][toIndex[re[i]]] = 1;

        solve(arr,mark,ans);

        if(!exist)
            cout << "NO" << endl;


        if(t)
            cout << endl;

        getline(cin,re);

        toIndex.clear();
        toChar.clear();
        exist = 0;

    }
}
