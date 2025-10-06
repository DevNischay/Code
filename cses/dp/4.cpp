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
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

dp[0] = 1
dp[i] => coins needed to make sum i. distinct ways

    -> let's say i know ans till all i-1.
        sum = 9
            2 + dp[7]
            3 + dp[6]
            5 + dp[4]
        i can take 2,3,5, if i know that all of them will 
        make distinct sequence.

        how ?
        before we had 3,5 and 2,5
        now if i add 2 or 3 it will given same.

        at every index keep track of number of coins[i] picked.

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
    for(auto c:coins) {
        for(int i=1;i<=sum;i++) {
            if(i>=c) {
                dp[i] += dp[i-c];
                dp[i] = dp[i] % mod7;
            }
        }
    }
    
    cout<<(dp[sum])<<endl;
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
