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

template <typename T>
void print_vec(const vector<T> &v)
{
    for (const auto &el : v)
        cout << el << " ";
    cout << endl;
}

template <typename T>
void read_vec(vector<T> &v, int n)
{
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

template <typename T>
T gcd(T a, T b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b)
{
    return (a / gcd(a, b)) * b;
}

template <typename T>
bool is_prime(T n)
{
    if (n < 2)
        return false;
    for (T i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

template <typename T>
T power(T a, T b, T mod)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

template <typename T>
T modinv(T a, T m)
{
    return power(a, m - 2, m);
}

// Disjoint Set Union
struct DSU
{
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

// Sieve of Eratosthenes
vector<int> sieve(int n)
{
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.pb(i);
            for (long long j = 1LL * i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

void solve()
{
    // Your code here
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
