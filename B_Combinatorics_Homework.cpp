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
    int a[3], m, minpair, maxpair, t = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    sort(a, a + 3);
    t = (a[0] + a[1] - a[2] + 1) / 2;
    if (a[0] >= t && a[1] >= t && (a[0] + a[1] + 1 >= a[2]))
    {
        minpair = 0;
    }
    else
    {
        minpair = (a[2] - a[1]) / 2;
    }
    maxpair = (a[0] - 1) + (a[1] - 1) + (a[2] - 1);
    if (m >= minpair && m <= maxpair)
    {
        cout << "YES";
    }
    // else if (a[0] + a[1] + 1 == a[2]) //|| (a[0]==a[1]!=1 && a[0] + a[1] + 1 >= a[2]))
    // {
    //     cout << "YES";
    // }
    else
        cout << "NO";
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