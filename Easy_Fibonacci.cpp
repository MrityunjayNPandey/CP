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
    int n, temp = 1, p = 1, q = 0, r = 0, s = 0, t = 0, a[2] = {0, 1}, f = 0;
    cin >> n;
    //vector<int> v;
    for (int i = 0; i < n - 2; i++)
    {
        f = a[1] + a[0];
        a[0] = a[1];
        a[1] = f;
        temp += f;
        //cout<<temp<<" ";
    }
    cout << endl;
    //cout<<temp<<endl;
    while (temp > 0)
    {
        //cout<<"rri"<<endl;
        p *= 10;
        q = temp % p;
        temp -= q;
        q = (q * 10) / p;
        r += q;
    }
    //cout<<r<<endl;
    p = 1;
    while (r > 0)
    {
        //cout<<"rri"<<endl;
        p *= 10;
        s = r % p;
        r -= s;
        s = (s * 10) / p;
        //cout<<s<<"gjgy"<<endl;
        t += s;
    }
    cout << t;
}

int32_t main()
{
    ios;
    int Test = 1;
    //cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        //cout << endl;
    }
}