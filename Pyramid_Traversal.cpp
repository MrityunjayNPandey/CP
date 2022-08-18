#include <bits/stdc++.h>
using namespace std;
#define pb push_back
// #define int long long
#define ll long long
#define lli long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define free                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long int MOD_N = 1e9 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;

int I;
unordered_map<int, int> mp;

unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

// void pref()
// {
//     int t = 1;
//     while (t < MAX_N)
//     {
//         mp[t++] = ((t) * (t + 1)) / 2;
//     }
// }
int last_elem(int lvl)
{
    return ((lvl + 1) * lvl) / 2;
}
void solve()
{
    int s, e, l1, l2;
    cin >> s >> e;
    if (s > e)
        cout << 0;
    else
    {
        {
            if (s == 1)
                l1 = 1;
            else
            {
                int l1st = 2;
                int l1end = 1 + ceil(sqrt(2 * s));
                while (l1st <= l1end)
                {
                    l1 = (l1st + l1end) / 2;
                    if (last_elem(l1) >= s && last_elem(l1 - 1) < s)
                    {
                        break;
                    }
                    else if (last_elem(l1) > s)
                        l1end = l1 - 1;
                    else
                    {
                        l1st = l1 + 1;
                    }
                }
            }
        }
        {
            if (e == 1)
                l2 = 1;
            else
            {
                int l2st = 2;
                int l2end = 1 + ceil(sqrt(2 * e));
                while (l2st <= l2end)
                {
                    l2 = (l2st + l2end) / 2;
                    if (last_elem(l2) >= e && last_elem(l2 - 1) < e)
                    {
                        break;
                    }
                    else if (last_elem(l2) > e)
                        l2end = l2 - 1;
                    else
                    {
                        l2st = l2 + 1;
                    }
                }
            }
        }
        int L = l2 - l1, i1, i2;
        i1 = s - (l1 * (l1 - 1) / 2);
        i2 = e - (l2 * (l2 - 1) / 2);
        int K = i2-i1;
        cout << L << " " << K << endl;
        if (L > 0 && L >= K )
        {
            int ans = nCrModPFermat(L, K, MOD_N);
            cout << ans;
        }
        else
            cout << 0;
    }
}
int32_t main()
{
    ios;
    int Test = 1;
    // pref();
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        cout << "\n";
    }
}
