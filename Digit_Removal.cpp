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
    int d, t = -1, mult = 1, semians = 0, q = 0, s = 0;
    string n;
    cin >> n >> d;
    // for (int i = 0; i < n.str; i++)
    // {
    //     scanf("%1d",n);
    // }
    int p = n.length();
    int a[p];

    for (int i = 0; i < p; i++)
    {
        a[i] = (int)n[i] - '0';
    }
    if (d == 0)
    {
        for (int i = 0; i < p; i++)
        {
            if (a[i] > 0)
            {
                q++;
            }
            if (q != 0)
            {
                if (a[i] == 0)
                {
                    a[i] = 1;
                    s = 1;
                }
                if (s == 1)
                {
                    a[i] = 1;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < p; i++)
        {
            if (a[i] == d)
            {
                a[i]++;
                t = i;
                if (a[i] == 10)
                {
                    for (int j = i; j >= 0; j--)
                    {
                        if (a[j] == 10)
                        {
                            a[j] = 0;
                            a[j - 1]++;
                        }
                    }
                }
                break;
            }
        }
        if (t != -1)
        {
            for (int i = t + 1; i < p; i++)
            {
                a[i] = 0;
            }
        }
    }
    for (int i = p - 1; i >= 0; i--)
    {
        semians += a[i] * mult;
        mult *= 10;
        //cout << a[i] << endl;
    }
    stringstream geek(n);
    int x = 0;
    geek >> x;
    cout << semians - x;
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