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

/**
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input:
3 11
1 5 7

Output:
3

dp[i] => min coins needed to make sum i.
    -> dependent on ?
        1 + min( dp[i-5] , dp[i-1], dp[i-7])
                take 5.    take 1.   take 7
*/

void solve()
{
    ll n, sum;
    cin>>n>>sum;

    vector<ll> coins(n, 0);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    vector<ll> dp(sum+1, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=sum;i++) {
        ll ways = INT_MAX;
        for(auto c:coins) {
            if(i-c>=0) {
                ways = min(ways, dp[i-c]);
            }
        }
        if(ways==INT_MAX) continue;
        dp[i] = 1 + ways;
    
    }
    if(dp[sum]==INT_MAX)
        cout<<"-1"<<endl;
    else
        cout<<dp[sum]<<endl;
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
