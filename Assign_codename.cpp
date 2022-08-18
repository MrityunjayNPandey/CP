#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
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
const long long MOD = 998244353;
const long long mod = 998244353;
int I;
void solve()
{
    string str;
    cin >> str;
    string ans;
    if (str.length() > 5)
    {
        // ans = str[0];
        // ans += ((str.length() - 2) + //'0'//);
        // ans += str[str.length() - 1];
        cout << str[0] << str.length() - 2 << str[str.length() - 1];
    }
    else
    {
        ans = str;
        cout << ans << nl;
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
    }
}