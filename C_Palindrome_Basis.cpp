/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 30-04-2022 21:20:46
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

int reverse(int n)
{
    int r = 0;
    while(n > 0)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int checkPalendrome(int n)
{
    return reverse(n) == n;
}

vector<int> palendrome;
int dp[40004][502];

void pref()
{
    for(int i = 0; i < 2 * 40004; i++) if(checkPalendrome(i)) palendrome.push_back(i);
    debug(palendrome)
    for(int j = 1; j < 502; j++) dp[0][j] = 1;
    for(int i = 1;i < 40004;i++)
    {
        dp[i][0] = 0;
        for(int j = 1;j < 502;j++)
        {
            if(palendrome[j] <= i)
                dp[i][j] = (dp[i][j - 1] + dp[i - palendrome[j]][j]) % MOD;
            else
            dp[i][j] = dp[i][j - 1];
        }
    }
    for(int i = 0;i < 40004;i++)
    {
        for(int j = 1;j < 502;j++)
        {
            clog<<dp[i][j]<<" ";
        }
        clog<<endl;
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    cout << dp[n][501];
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        pref();
    int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

