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
        seg[tree_idx] = (seg[(2*tree_idx)+1] + seg[(2*tree_idx)+2]);
    }

    int query(int tree_idx, int low, int high, int l, int r) {
        if (r<low || l>high) {
            return 0;
        }
        if (l<=low && high<=r) {
            return seg[tree_idx];
        }
        int mid = (low+high)/2;
        int ans1 = query((2*tree_idx)+1, low, mid, l, r);
        int ans2 = query((2*tree_idx)+2, mid+1, high, l, r);
        
        return (ans1 + ans2);
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

        seg[tree_idx] = (seg[(2*tree_idx)+1] + seg[(2*tree_idx)+2]);
    }
    void print() {
        for(auto a:seg) {
            cout<<a<<" ";
        }cout<<endl;
    }
};
int countInversions(vector<int> a, int n) {
    // code here
    vector<int> arr;
    vector<int> sarr;
    for(int i=0;i<n;i++) {
        arr.push_back(a[i]);
        sarr.push_back(a[i]);
    }
    sort(sarr.begin(), sarr.end());

    unordered_map<int,int> mp;
    vector<int> freq;
    int idx = 0;
    for (int i=0;i<sarr.size();i++) {
        if (mp.find(sarr[i])!=mp.end()) {
            freq[mp[sarr[i]]]++;
        } else {
            freq.push_back(1);
            mp[sarr[i]] = idx;
            idx++;
        }
    }
    for(int i=0;i<freq.size();i++) {
        cout<<freq[i]<<" ";
    }cout<<endl;

    Seg* s = new Seg(freq);
    int r = freq.size()-1;
    int l = 0;
    // s->print();

    int inv = 0;
    for(int i=0;i<arr.size();i++) {
        int f_idx = mp[arr[i]];
        cout<<arr[i]<<" "<<f_idx<<" "<<freq[f_idx]<<endl;

        s->update(0,l,r,f_idx, freq[f_idx]-1);
        freq[f_idx]--;
        
        // cout<<(s->query(0,l,r,0,f_idx-1))<<endl;
        inv = inv + s->query(0,l,r,0,f_idx-1);

        // s->print();
    }

    return inv;
}

int main() {
    cout<<countInversions({10 ,10 ,10}, 3);
    
    // vector<int> arr = {2,1,0,4,3,7};
    // int n = arr.size();
    // Seg* s = new Seg(arr);
    // s->print();
    // s->update(0,0,n-1,2,5);
    // s->print();
    // cout<<(s->query(0, 0, n-1, 0,2))<<endl;

}