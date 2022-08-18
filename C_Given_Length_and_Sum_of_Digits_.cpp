// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define free freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x...) cerr<< "[" << __LINE__ <<"] "<< #x <<" = "; _print(x);
#else
#define debug(x...)
#endif
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void _print() {cerr << "\n";}
template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
// #define int long long
int I;
// clang-format on
int ans[110];
void solve()
{
    // debug(ans)
    int len, s, ts, i;
    while (~scanf("%d%d", &len, &s))
    {
        if (len > 1 && s == 0 || len * 9 < s)
        {
            printf("-1 -1\n");
            continue;
        }
        else if (len == 1 && s == 0)
        {
            printf("0 0\n");
            continue;
        }
        memset(ans, 0, sizeof(ans));
        ans[1] = 1;
        ts = s - 1;
        for (i = len; i >= 1; i--)
        {
            ans[i] += min(9, ts);
            ts -= min(9, ts);
        }
        for (i = 1; i <= len; i++)
            printf("%c", ans[i] + '0');
        printf(" ");

        memset(ans, 0, sizeof(ans));
        ts = s;
        for (i = 1; i <= len; i++)
        {
            ans[i] += min(9, ts);
            ts -= min(9, ts);
        }
        for (i = 1; i <= len; i++)
            printf("%c", ans[i] + '0');
        printf("\n");
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {   debug(I)
        cerr << "-------" << I << "-------" << nl;
        solve();
        cout << endl;
    }
}
