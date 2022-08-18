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
    int n = 0, ans = 0, p = 0, q = 1;
    cin >> n;
    while (n--)
    {
        cout << pow(2, p) + pow(2, q) << " ";
        if (p >= 1)
        {
            int r = 0, s = 1;
            for (int i = 0; i < (p) / 2; i++)
            {
                if (n <= 1)
                    break;
                n--;
                cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) << " ";
                if (r >= 1)
                {
                    int t = 0, u = 1;
                    for (int i = 0; i < (r) / 2; i++)
                    {
                        if (n <= 1)
                            break;
                        n--;
                        cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) << " ";
                        if (t >= 1)
                        {
                            int v = 0, w = 1;
                            for (int i = 0; i < (t) / 2; i++)
                            {
                                if (n <= 1)
                                    break;
                                n--;
                                cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) + pow(2, v) + pow(2, w) << " ";
                                if (v >= 1)
                                {
                                    int x = 0, y = 1;
                                    for (int i = 0; i < (v) / 2; i++)
                                    {
                                        if (n <= 1)
                                            break;
                                        n--;
                                        cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) + pow(2, v) + pow(2, w) + pow(2, x) + pow(2, y) << " ";
                                        if (x >= 1)
                                        {
                                            int x1 = 0, y1 = 1;
                                            for (int i = 0; i < (x) / 2; i++)
                                            {
                                                if (n <= 1)
                                                    break;
                                                n--;
                                                cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) + pow(2, v) + pow(2, w) + pow(2, x) + pow(2, y) + pow(2, x1) + pow(2, y1) << " ";
                                                if (x1 >= 1)
                                                {
                                                    int x12 = 0, y12 = 1;
                                                    for (int i = 0; i < (x1) / 2; i++)
                                                    {
                                                        if (n <= 1)
                                                            break;
                                                        n--;
                                                        cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) + pow(2, v) + pow(2, w) + pow(2, x) + pow(2, y) + pow(2, x1) + pow(2, y1) + pow(2, y) + pow(2, x12) + pow(2, y12) << " ";
                                                        if (x12 >= 1)
                                                        {
                                                            int x121 = 0, y121 = 1;
                                                            for (int i = 0; i < (x12) / 2; i++)
                                                            {
                                                                if (n <= 1)
                                                                    break;
                                                                n--;
                                                                cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) + pow(2, v) + pow(2, w) + pow(2, x) + pow(2, y) + pow(2, x1) + pow(2, y1) + pow(2, y) + pow(2, x12) + pow(2, y12) + pow(2, x121) + pow(2, y121) << " ";
                                                                if (x121 >= 1)
                                                                {
                                                                    int x1212 = 0, y1212 = 1;
                                                                    for (int i = 0; i < (x121) / 2; i++)
                                                                    {
                                                                        if (n <= 1)
                                                                            break;
                                                                        n--;
                                                                        cout << pow(2, p) + pow(2, q) + pow(2, r) + pow(2, s) + pow(2, t) + pow(2, u) + pow(2, v) + pow(2, w) + pow(2, x) + pow(2, y) + pow(2, x1) + pow(2, y1) + pow(2, y) + pow(2, x12) + pow(2, y12) + pow(2, x121) + pow(2, y121) + pow(2, x1212) + pow(2, y1212) << " ";
                                                                        x1212 += 2;
                                                                        y1212 += 2;
                                                                        debug(n);
                                                                    }
                                                                }
                                                                x121 += 2;
                                                                y121 += 2;
                                                                debug(n);
                                                            }
                                                        }
                                                        x12 += 2;
                                                        y12 += 2;
                                                        debug(n);
                                                    }
                                                }
                                                x1 += 2;
                                                y1 += 2;
                                                debug(n);
                                            }
                                        }
                                        x += 2;
                                        y += 2;
                                        debug(n);
                                    }
                                }
                                v += 2;
                                w += 2;
                                debug(n);
                            }
                        }
                        t += 2;
                        u += 2;
                        debug(n);
                    }
                }
                r += 2;
                s += 2;
                debug(n);
            }
        }
        p += 2;
        q += 2;
        debug(n);
        if (n < 1)
            break;
        if (n == 0)
            debug(pow(2, p) + pow(2, q));
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
        cout << endl;
    }
}
