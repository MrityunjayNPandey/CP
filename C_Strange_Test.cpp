// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;

        // do something, stay focused
        // look for stupid bugs
        // guess, slow, stress
        // don't overgeneralize
        // don't rush
            
        // 1. Understand the problem
        // 2. Devise a plan
        // 3. Carry out the plan
        // 4. Look back
            
        // don't waste time on standings
            
        // SOLVE THE PROBLEM OR DIE TRYING
        // THE SOLUTION IS ALWAYS SIMPLE
        // THE CODE IS ALWAYS SHORT

// clang-format on

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = b - a;
    for (int a1 = a; a1 < b; a1++)
    {
        int b1 = 0;
        for (int i = 21; i >= 0; i--)
        {
            if ((b >> i) & 1)
            {
                b1 ^= (1 << i);
            }
            else
            {
                if ((a1 >> i) & 1)
                {
                    b1 ^= (1 << i);
                    break;
                }
            }
        }
        ans = min(ans, a1 - a - b + (a1 | b1) + 1);
    }
    cout << ans;
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
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
