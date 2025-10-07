#include<bits/stdc++.h>
using namespace std;

class Seg{
    public:
    vector<int> seg;
    vector<int> arr;
    Seg(vector<int> ip){
        arr = ip;
        int n = arr.size();
        seg.resize(4*n, 0);

        build(0, 0, n-1);
    }

    bool build(int tree_idx, int low, int high) {
        if (low==high) {
            seg[tree_idx] = arr[low];
            return true; // 1 -> OR, 0-> XOR
        }
        int mid = (low+high)/2;
        bool l = build((2*tree_idx)+1, low, mid);
        bool r = build((2*tree_idx)+2, mid+1, high);

        if (l) {
            seg[tree_idx] = seg[(2*tree_idx)+1] | seg[(2*tree_idx)+2];
        } else {
            seg[tree_idx] = seg[(2*tree_idx)+1] ^ seg[(2*tree_idx)+2];
        }
        return !l;
    }

    int query() {
        return seg[0];
    }

    bool update(int tree_idx, int low, int high, int i, int v) {
        if (low==high) {
            seg[tree_idx] = v;
            return true;
        }
        int mid = (low+high)/2;
        bool l;
        if(i<=mid) 
            l = update((2*tree_idx)+1, low, mid, i, v);
        else
            l = update((2*tree_idx)+2, mid+1, high, i, v);


        if (l) {
            seg[tree_idx] = seg[(2*tree_idx)+1] | seg[(2*tree_idx)+2];
        } else {
            seg[tree_idx] = seg[(2*tree_idx)+1] ^ seg[(2*tree_idx)+2];
        }
        return !l;
        
    }

    void print() {
        for(auto a:seg) {
            cout<<a<<" ";
        }cout<<endl;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> arr(1<<n);
    for(int i=0;i<(1<<n);i++) {
        cin>>arr[i];
    }
    int sz = arr.size();
    Seg* tr = new Seg(arr);
    while(m--) {
        int i,v;
        cin>>i>>v;
        tr->update(0,0,sz-1,i,v);
        cout<<(tr->query())<<endl;
    }
}