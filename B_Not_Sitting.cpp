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
const long long MAX_N = 1e5 + 7;
const long long MOD = 1e9 + 7;
const long long N = 1e3 + 5;

int I;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int _ans = max(i - 1, n - i) + max(j - 1, m - j);
            ans.pb(_ans);
        }
    }
    sort(all(ans));
    for (auto it : ans)
        cout << it << " ";
    cout << nl;
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