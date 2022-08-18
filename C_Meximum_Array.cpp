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
#define debug(x) cerr << #x<<" = ";  _print(x); cerr << endl;
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
#define int long long
int I;
// clang-format on

void solve()
{
    long long i,j,k,l,r,n,m,t,x,y,z,p;
    cin >> n;
    long long a[n], b[n];
    vector<long long> v[n];
    vector<long long> u;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 0;
        if (a[i] < n)
        {
            v[a[i]].push_back(i);
        }
    }
    z = -1;
    p = 0;
    while (p < n)
    {
        y = z;
        for (i = 0; i < n; i++)
        {
            j = b[i];
            while (j < v[i].size() && v[i][j] <= z)
            {
                j++;
            }
            if (j >= v[i].size())
                break;
            y = max(y, v[i][j]);
            j++;
            b[i] = j;
        }
        if (i == 0)
            y++;
        z = y;
        p = z + 1;
        if (p == 0)
            p = 1;
        u.push_back(i);
    }
    cout << u.size() << "\n";
    for (i = 0; i < u.size(); i++)
    {
        cout << u[i] << " ";
    }
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
