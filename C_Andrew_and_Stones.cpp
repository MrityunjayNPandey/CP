#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear()
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int t,n,a[100005],cnt,ans;
    ans = 0;
    cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(i > 1 && i < n)
        {
            ans += (a[i] + 1) / 2;
            if(a[i] >= 2) cnt++;
        }
    }
    if(cnt == 0 || (n == 3 && (a[2] & 1))) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;dclear();
        solve();
        // cout << endl;
    }
}

