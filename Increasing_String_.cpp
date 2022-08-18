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
    int n;
    string str, str1, str2;
    cin>>str;
    // cout<<str<<endl;
    vector<pair<char, int>> vp;
    vector<pair<int, char>> vp1;
    for (int i = 0; i < str.length(); i++)
    {
        vp.pb(make_pair(str[i], i));
    }
    sort(all(vp));
    int k = 0, l = 0;
    for (int i = 0; i < vp.size(); i++)
    {
        if (i != 0 && vp[i].ss == 0)
        {
            l++;
        }
        if (vp[i].ss >= k && l == 0)
        {
            str1 += vp[i].ff;
            k = vp[i].ss;
        }
        else
            vp1.pb(make_pair(vp[i].ss, vp[i].ff));
    }
    sort(all(vp1));
    for (int i = 0; i < vp1.size(); i++)
    {
        str2 += vp1[i].ss;
    }
    cout<< str1+str2;
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
