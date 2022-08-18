#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
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
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;
int n = 0, k = 0, ans = 0;
int nb, ns, nc, rb = 0, rs = 0, rc = 0, prb, prs, prc;
int r;
bool binary_Search(int mid)
{
    int totb, tots, totc;
    totb = (rb * mid) - nb;
    tots = (rs * mid) - ns;
    totc = (rc * mid) - nc;
    int cost = 0;
    if(totb > 0)
        cost += (totb * prb);
    if(tots > 0)
        cost += (tots * prs);
    if(totc > 0)
        cost += (totc * prc);
    debug(cost)
    if(cost <= r)
        return true;
    return false;
}
void solve()
{
    string str;
    cin >> str;
    cin >> nb >> ns >> nc >> prb >> prs >> prc;
    cin >> r;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'B')
            rb++;
        else if(str[i] == 'S')
            rs++;
        else
            rc++;
    }
    int start = 0;
    int max = 1e14;
    ans = 0;
    debug(start, max, ans, nb, ns, nc, rb, rs, rc, prb, prs, prc)
        while(start <= max)
        {
            int mid = start + (max - start) / 2;
            if(binary_Search(mid))
            {
                ans = mid;
                start = mid + 1;
            } else
            {
                max = mid - 1;
            }
            debug(ans, mid, start, max)
        }
    cout << ans;
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;
        solve();
        cout << endl;
    }
}

