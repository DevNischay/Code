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
#define mod 1000000007
/**
    given -> 1-6
    number of ways to bring sum  = n

    dp[i] => number of ways to bring sum = i
    dp[i] will be dependent on what ?
    -> dp[i-1], dp[i-2], dp[i-3], dp[i-4], dp[i-5], dp[i-6]
    get 1 more.   2 more.  3 more.   4 more.   5 more.   6 more.
 */

void solve()
{
    ll n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        int s = 0;
        for(int j=1;j<=6;j++) {
            if (i-j >= 0) {
                s += dp[i-j];
                s = s % mod;
            } else {
                break;
            }
        }
        dp[i] = s % mod;
    }
    cout<<dp[n]<<endl;
}

int main()
{
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
