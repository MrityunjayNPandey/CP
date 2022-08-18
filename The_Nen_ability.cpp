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
    int n = str.length();
    int p = 0;
    vector<int> v;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            if (i <= str.length() - 3)
            {
                if (str[i] == str[i + 1] && str[i] == str[i + 2])
                {
                    str[i] = '0';
                    str[i + 1] = '0';
                    str[i + 2] = '0';
                    i = i + 2;
                    if (i >= str.length())
                        break;
                }
            }
        }
    }
    cout << str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
            v.pb(i);
    }
    int t = 0;
    if ((v.size()) % 3 != 0)
        cout << "No";
    else
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (t == 2)
            {
                i++;
                t = 0;
            }
            if ((v[i + 1] - v[i]) % 3 != 1)
            {
                cout << "No";
                p++;
                break;
            }
            t++;
        }
        if (p == 0)
        {
            cout << "Yes";
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
