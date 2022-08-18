// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
typedef vector<ll> vl;
// #define int long long
int I;
// clang-format on

void readvl(vl &v,ll n)
{
    for(ll i=0; i<n; i++)cin>>v[i];
}
bool isprime(long long int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    a = a % mod;
    while (b)
    {
        if (b & 1)
            ans = (ans * a);
        b /= 2;
        a = (a * a);
        ans %= mod;
        a %= mod;
    }
    return ans;
}

// 315 :-> 3 3 5 7
void primeFactors(ll n, map<ll, ll> &mp)
{
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        mp[n]++;
}

ll lengthOfLIS(vector<ll> &a)
{
    ll n = a.size();
    vector<ll> len;
    for (ll i = 0; i < n; i++)
    {
        auto lb = upper_bound(len.begin(), len.end(), a[i]);
        if (lb != len.end())
        {
            *lb = min(*lb, a[i]);
        }
        else
        {
            len.push_back(a[i]);
        }
    }
    return len.size();
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vl a(n), b(m);
    readvl(a, n);
    readvl(b, m);
    ll mx1 = 1, mx2 = 1;
    mx1 = lengthOfLIS(a);
    mx2 = lengthOfLIS(b);
    cout << mx1 + mx2 ;
}

int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        cerr << "----" << I << "----" << nl;
        solve();
        cout << endl;
    }
}
