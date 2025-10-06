#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define endl '\n'
#define sz(x) ((int)(x).size())
#define mod7 1000000007

/** 

 */

void solve()
{
    ll r,c;
    cin>>r>>c;

    if (r<c) {
        cout<<"2\n";
    } else {
       if (((r+1)>(2*c)) && (r-c>=2) && (c>=2)) {
            cout<<"3\n";
       } else {
            cout<<"-1\n";
       }
    }
}
 
int main()
{
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
