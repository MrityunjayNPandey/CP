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
    int n, group=0, t=1, p=0;
    string str;
    cin>>str;
    n=str.length();
    for(int i=0;i<n;i++)
        {
            if(str[i]=='1' && t==1)
                {
                    group++;
                    t++;
                    p++;
                }
            else if(str[i]=='0')
                {
                    t=1;
                }
        }
    cout<<group;
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