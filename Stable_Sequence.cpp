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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    for(int i=0; i<n; i++)
        {
            cin>>a[i];
            v.pb(a[i]);
        }
    int p=0;
    for(int i=0; i<n-1; i++)
        {
            if(a[i]!=a[i+1])
                p++;
                break;
        } 
    if(p==0)
        {cout<<0;}
    else
        {
            sort(all(v));
            if(v[n-1]!=a[n-1])
                {
                    cout<<2;
                }
            else
                cout<<1;
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
