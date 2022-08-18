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
const long long N = 1e12 + 7;
const long long MOD = 1e9 + 7;

int I;

void solve()
{
    int n;
    cin >> n;
    vector<int> z[n + 1];
    map<pii, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        z[u].pb(v);
        z[v].pb(u);
        mp[{u, v}] = c;
        mp[{v, u}] = c;
    }
    function<int(int, int)> dfs = [&](int t, int p)
    {
        int ans = 0;
        for (auto it : z[t])
        {
            if (it == p)
                continue;
            ans = max(ans, dfs(it, t) + mp[{t, it}]);
        }
        return ans;
    };
    cout << dfs(0, -1);
}

int32_t main()
{
    ios;
    int Test = 1;
    // cin>>Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
    }
}