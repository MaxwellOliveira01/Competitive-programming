//const int MAXN = 3e5 + 10;
//vector<int> seg[ 4 * MAXN + 10];

struct MergeSortTree {

//quantidade de valores >= x no intervalo [l, r] em O(log^2N)
//Sem updates, build em O(nlogn)

    int n; //size do array que a seg vai ser criada em cima
    vector< vector<int> > seg;

    Segtree(vector<int>& s){
        //se o input for grande (ou o tempo mt puxado), coloca a seg com size
        //maximo de forma global
        n = (int)s.size();
        seg.resize(4 * n + 10);      
        seg_build(1,0,n-1,s);
    }

    vector<int> merge(vi& a, vi& b){
        int i = 0, j = 0, p = 0;
        vi ans(a.size() + b.size());
        while(i < (int)a.size() && j < (int)b.size()){
            if(a[i] < b[j]){
                ans[p++] = a[i++];
            } else {
                ans[p++] = b[j++];
            }
        }
        while(i < (int)a.size()){
            ans[p++] = a[i++];
        }
        while(j < (int)b.size()){
            ans[p++] = b[j++];
        }
        return ans;
    }

    void seg_build(int x, int l, int r, vector<int>& s){
        if(r < l) return;
        if(l == r){
            seg[x].push_back(s[l]);
        } else {
            int mid = l + (r-l)/2;
            seg_build(x+x, l, mid, s);
            seg_build(x+x+1, mid+1, r, s);
            seg[x] = merge(seg[x+x], seg[x+x+1]);
        }
    }
    //nó atual, intervalo na árvore e intervalo pedido
    ll q(int x, int l, int r, int i, int j, int val){
        if(r < i || l > j ) return 0;
        if(l >= i && r <= j ){
            return (lower_bound(seg[x].begin(), seg[x].end(), val)  - seg[x].begin());
        }
        int mid = l + (r-l)/2;        
        return q(x+x,l,mid,i,j, val) + q(x+x+1,mid+1,r,i,j, val);
    }
    ll query(int l, int r, int val){
        return q(1, 0, n-1, l, r, val);
    }
};