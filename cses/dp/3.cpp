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
    Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
        For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
        2+2+5
        2+5+2
        5+2+2
        3+3+3
        2+2+2+3
        2+2+3+2
        2+3+2+2
        3+2+2+2

    Input:
    3 9
    2 3 5
    Output:
    8

dp[0] = 1
dp[i] => coins needed to make sum i.
    -> dependent on ?
        dp[i-2] + dp[i-3]+ dp[i-5]
   can take 2.    take 3.   take 5
*/

void solve()
{
    ull n, sum;
    cin>>n>>sum;

    vector<ull> coins(n, 0);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    vector<ull> dp(sum+1, 0);
    dp[0] = 1;
    for(ull i=1;i<=sum;i++) {
        ull ways = 0;
        for(auto c:coins) {
            if(i>=c) {
                ways += dp[i-c];
                ways = ways % mod7;
            }
        }
        dp[i] = ways;
    
    }
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
