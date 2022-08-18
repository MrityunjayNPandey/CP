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
    // int n, i, p = 0, q, j = 0, k = 0, l = 1, m = 0, o = 0, r = 0;
    // cin >> n;
    // int a[n], b[n];
    // char e[n][n];
    // vector<int> c, d;
    // vector<pii> v;
    // for (i = 0; i < n; i++)
    // {

    //     // %1d reads a single digit
    //     scanf("%1d", &a[i]);
    // }
    // for (i = 0; i < n; i++)
    // {
    //     b[i] = a[i];
    // }
    // sort(a, a + n);
    // for (int i = 0; i < n; i++)
    // {
    //     if (b[i] == '2')
    //     {
    //         c[j] = i;
    //         j++;
    //     }
    //     if (b[i] == '1')
    //     {
    //         d[k] = i;
    //         k++;
    //     }
    // }
    // j--;
    // k--;
    // c.shrink_to_fit();
    // d.shrink_to_fit();
    // for (i = 0; i < n; i++)
    // {
    //     if (a[i] != a[i + 1])
    //     {
    //         p = i + 1;
    //         break;
    //     }
    // }
    // if (p != 0)
    // {
    //     q = n - p;
    // }
    // if (q > 2 || q == 0)
    // {
    //     cout << "YES";
    //     for (i = 0; i < n; i++)
    //     {
    //         e[i][i] = 'X';
    //         for (j = 0; j < n; j++)
    //         {
    //             if (b[i] == '2' && l != 0)
    //             {
    //                 if (l + 1 == c.size())
    //                 {
    //                     l = 0;
    //                 }
    //                 e[i][c[l]] = '+';
    //                 e[c[l]][i] = '-';
    //                 l++;
    //                 e[i][d[m]] = '-';
    //                 m++;
    //             }
    //             else if (b[i] == '1')
    //             {
    //                 e[i][c[o]] = '+';
    //                 e[i][d[r]] = '=';
    //                 o++;
    //                 r++;
    //             }
    //         }
    //         o = 0;
    //         r = 0;
    //         l = 0;
    //         m = 0;
    //     }
    //     for (i = 0; i < n; i++)
    //     {
    //         for (j = 0; j < n; j++)
    //         {
    //             cout << e[i][j];
    //         }
    //         cout << endl;
    //     }
    // }
    // else
    // {
    //     cout << "NO";
    // }
    
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