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
Consider an n * n grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
Input
The first input line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.

Input:
4
....
.*..
...*
*...

Output:
3
 */

void solve()
{
    ll n;
    cin>>n;
    vector<vector<char>> graph(n,vector<char>(n,' '));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>graph[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    if(graph[0][0]=='*') dp[0][0] = 0;
    else dp[0][0] = 1;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            if(graph[i][j]=='*') continue;
            if(i-1>=0) {
                dp[i][j] += dp[i-1][j];
            }
            if(j-1>=0) {
                dp[i][j] += dp[i][j-1];
            }
			dp[i][j] = dp[i][j] % mod7;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
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
