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
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?

dp[i] = number of steps required to make it to 0, if we subtract one digit from number.

27 - 20 - 18 - 10 - 9 - 0

dp[0] = 0;
dp[1] till dp[9] = 1

dp[12] = 1+min(dp[10], dp[11])

 */

void solve()
{
    ll n;
    cin>>n;

    vector<ll> dp(n+1, 0);
    for(ll i=1;i<=n;i++) {
        ll ans = INT_MAX;
        ll num = i;
        while(num!=0) {
            int digit = num%10;
            num = num/10;
            if(digit!=0 && i>=digit) {
                ans = min(ans, dp[i - digit]);
            }
        }
        dp[i] = 1 + ans;
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
