// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0,k1=0, ans = 0;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for(int i= 0; i < n; i++)
    {
        if(v[i]!=v[n-1])
        break;
        else
        {
            k++;
        }
    }
    for (int i = n-1; i >=0; i--)
    {
        if(v[i]==v[n-1])
        {
            k1++;
        }
        if(v[i]!=v[n-1])
        {
            i-=k1;
            k1+=k1;
            ans++;
            i++;
            debug(v[i]);

        }
    }
    
    cout<<ans;
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef LOCAL
        cerr << "-------" << I << "-------" << nl;
        #endif
        solve();
        cout << nl;
    }
}
