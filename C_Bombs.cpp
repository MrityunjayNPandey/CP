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

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n;
    vector<tuple<float, int, int>> vt;
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        vt.pb({ (sqrt(pow(x, 2) + pow(y, 2))), x, y });
        if(x != 0)
            k++;
        if(y != 0)
            k++;
    }
    sort(rall(vt));
    debug(vt);
    cout << (2 * vt.size()) + (2 * k) << endl;
    while(vt.size() > 0)
    {
        if(get<1>(vt[vt.size() - 1]) != 0)
        {
            if(get<1>(vt[vt.size() - 1]) > 0)
            {
                cout << 1 << " " << get<1>(vt[vt.size() - 1]) << " " << "R" << endl;
            } else
            {
                cout << 1 << " " << -get<1>(vt[vt.size() - 1]) << " " << "L" << endl;
            }
        }
        if(get<2>(vt[vt.size() - 1]) != 0)
        {
            if(get<2>(vt[vt.size() - 1]) > 0)
            {
                cout << 1 << " " << get<2>(vt[vt.size() - 1]) << " " << "U" << endl;
            } else
            {
                cout << 1 << " " << -get<2>(vt[vt.size() - 1]) << " " << "D" << endl;
            }
        }
        cout << 2 << endl;
        if(get<2>(vt[vt.size() - 1]) != 0)
        {
            if(get<2>(vt[vt.size() - 1]) > 0)
            {
                cout << 1 << " " << get<2>(vt[vt.size() - 1]) << " " << "D" << endl;
            } else
            {
                cout << 1 << " " << -get<2>(vt[vt.size() - 1]) << " " << "U" << endl;
            }
        }
        if(get<1>(vt[vt.size() - 1]) != 0)
        {
            if(get<1>(vt[vt.size() - 1]) > 0)
            {
                cout << 1 << " " << get<1>(vt[vt.size() - 1]) << " " << "L" << endl;
            } else
            {
                cout << 1 << " " << -get<1>(vt[vt.size() - 1]) << " " << "R" << endl;
            }
        }
        cout << 3 << endl;
        // vt.erase(vt.begin()); --fuck this
        vt.pop_back();
    }
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
#ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
#endif
        solve();
        // cout << endl;
    }
}

