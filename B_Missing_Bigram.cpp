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
    int n, p = 0;
    cin >> n;
    string str;
    vector<pair<char, char>> vp;
    for (int i = 0; i < n - 2; i++)
    {
        cin >> str;
        vp.pb(make_pair(str[0], str[1]));
    }
    for (int i = 1; i < n - 2; i++)
    {
        // cout<<vp[i-1].ss<<" "<<vp[i].ff<<endl;
        if (vp[i].ff != vp[i - 1].ss)
        {
            vp.insert(vp.begin() + i, make_pair(vp[i - 1].ss, vp[i].ff));
            p++;
            break;
        }
    }
    if (p == 0)
    {
        cout << vp[0].ff;
        for (int i = 0; i < n - 2; i++)
        {
            cout << vp[i].ss;
        }
        cout << vp[n - 3].ss;
    }
    else
    {
        cout << vp[0].ff;
        for (int i = 0; i < n - 1; i++)
        {
            cout << vp[i].ss;
        }
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
