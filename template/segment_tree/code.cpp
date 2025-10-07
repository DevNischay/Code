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

    void build(int tree_idx, int low, int high) {
        if (low==high) {
            seg[tree_idx] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build((2*tree_idx)+1, low, mid);
        build((2*tree_idx)+2, mid+1, high);
        seg[tree_idx] = min(seg[(2*tree_idx)+1], seg[(2*tree_idx)+2]);
    }

    int query(int tree_idx, int low, int high, int l, int r) {
        if (r<low || l>high) {
            return INT_MAX;
        }
        if (l<=low && high<=r) {
            return seg[tree_idx];
        }
        int mid = (low+high)/2;
        int ans1 = query((2*tree_idx)+1, low, mid, l, r);
        int ans2 = query((2*tree_idx)+2, mid+1, high, l, r);
        
        return min(ans1, ans2);
    }

    void update(int tree_idx, int low, int high, int i, int v) {
        if (low==high) {
            seg[tree_idx] = v;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) 
            update((2*tree_idx)+1, low, mid, i, v);
        else
            update((2*tree_idx)+2, mid+1, high, i, v);

        seg[tree_idx] = min(seg[(2*tree_idx)+1], seg[(2*tree_idx)+2]);
    }
    void print() {
        for(auto a:seg) {
            cout<<a<<" ";
        }cout<<endl;
    }
};

int main() {
    vector<int> arr = {2,1,0,4,3,7};
    int n = arr.size();
    Seg* s = new Seg(arr);
    s->print();
    s->update(0,0,n-1,2,5);
    s->print();
    cout<<(s->query(0, 0, n-1, 0,2))<<endl;
}