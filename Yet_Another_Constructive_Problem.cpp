// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef joKer
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
    int x = 0, k = 0, ans = 0, a = 0, b = 0, c = 0;
    cin >> x;
    string number;
    long i;
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((x & i) != 0)
        {
            number.push_back('1');
        }
        else
        {
            number.push_back('0');
        }
    }
    int t = 0;
    for (int i = number.size() - 1; i >= 0; i--)
    {
        if (number[i] == '1')
            break;
        t++;
    }
    debug(t);
    a = x - pow(2, t);
    b = x;
    c = pow(2, t);
    if (a == 0)
    {
        if (b == 1)
        {
            a = 0;
            b = 1;
            c = 5;
        }
        else
        {
            a = b;
            b = b + 1;
            c = b + 1;
        }
    }
    cout << a << " " << b << " " << c;
    debug((a | b) & (b | c) & (c | a))
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
