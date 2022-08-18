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
    int n, m;
    cin >> n >> m;
    if (n < m)
    {
        if (n + 1 == m)
        {
            cout << n + m + 2 << endl;
            for (int i = 0; i < n + m + 2; i++)
            {
                if (i % 2 == 0)
                    cout << 1;
                else
                    cout << 0;
            }
        }
        else
        {
            cout << ((m - n - 1) * 3) + (n + n + 1 + 2) << endl;
            for (int i = 0; i < n + n + 1 + 2; i++)
            {
                if (i % 2 == 0)
                    cout << 1;
                else
                    cout << 0;
            }
            for (int i = 0; i < m - n - 1; i++)
            {
                cout << "101";
            }
        }
    }
    else
    {
        if (m + 1 == n  || n == m)
        {
            cout << n + m + 2 << endl;
            for (int i = 0; i < n + m + 2; i++)
            {
                if (i % 2 == 0)
                    cout << 0;
                else
                    cout << 1;
            }
        }
        else
        {
            cout << ((n - m - 1) * 3) + (m + m + 1 + 2) << endl;
            for (int i = 0; i < m + m + 1 + 2; i++)
            {
                if (i % 2 == 0)
                    cout << 0;
                else
                    cout << 1;
            }
            for (int i = 0; i < n - m - 1; i++)
            {
                cout << "010";
            }
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
