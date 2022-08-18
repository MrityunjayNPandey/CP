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
#define debug(x...) cerr << __LINE__ <<" "<< #x <<" = "; _print(x);
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

void solve()
{
    int a[102400],b[102400],n,m,i,j,t,g;
    char o[102400],c;
    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; ++i)
        if (!a[i])
            for (j = i; j <= n; j += i)
                a[j] = i;
    while (m--)
    {
        scanf(" %c%d", &c, &i);
        if (c == '+')
        {
            if (o[i])
            {
                puts("Already on");
                continue;
            }
            g = 1;
            for (j = i; j > 1;)
            {
                t = a[j];
                if (b[t])
                {
                    printf("Conflict with %d\n", b[t]);
                    g = 0;
                    break;
                }
                do
                {
                    j /= t;
                } while (j % t == 0);
            }
            if (g)
            {
                puts("Success");
                o[i] = 1;
                for (j = i; j > 1;)
                {
                    b[t = a[j]] = i;
                    do
                        j /= t;
                    while (j % t == 0);
                }
            }
        }
        else
        {
            if (!o[i])
            {
                puts("Already off");
                continue;
            }
            for (j = i; j > 1;)
            {
                b[t = a[j]] = 0;
                do
                    j /= t;
                while (j % t == 0);
            }
            o[i] = 0;
            puts("Success");
        }
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << nl;
        solve();
        cout << endl;
    }
}
