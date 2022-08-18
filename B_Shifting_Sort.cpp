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
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n;
    vector<int> v;
    vector<pii> vp;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
        vp.pb(make_pair(temp, i));
        if (i > 0 && temp < v[i - 1])
            k++;
    }
    sort(all(vp));
    if (k == 0)
    {
        cout << 0 << endl
             << nl;
        return;
    }
    else
    {
        debug(v)
            vector<int>
                l, r, d;
        k = 0;
        for (int i = 0; i < n; i++)
        {
            debug(i);
            debug(vp[i].ss);
            if (vp[i].ss != i)
            {
                l.pb(i);
                r.pb(vp[i].ss);
                d.pb(vp[i].ss - i);
                debug(l);
                debug(r);
                debug(v[vp[i].ss]);
                k++;
                vector<int> temp;
                for (int j = 0; j < i; j++)
                {
                    temp.pb(v[j]);
                }
                temp.pb(v[vp[i].ss]);
                for (int j = i; j < vp[i].ss; j++)
                {
                    temp.pb(v[j]);
                }
                for (int j = vp[i].ss + 1; j < n; j++)
                {
                    temp.pb(v[j]);
                    debug(v[j])
                }
                debug(temp);
                v.clear();
                vp.clear();
                v = temp;
                for (int i = 0; i < n; i++)
                {
                    vp.pb(make_pair(v[i], i));
                }
                sort(all(vp));
                debug(vp);
                debug(v);
                debug(k);
            }
        }
        cout << k << nl;
        for (int i = 0; i < k; i++)
            cout
                << l[i] + 1 << " " << r[i] + 1 << " " << d[i] << nl;
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        // cout << endl;
    }
}
