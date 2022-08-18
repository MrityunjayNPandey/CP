/**
*      author: demoralizer
*      created: 19-02-2022 16:30:34
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear()
#endif
#define firstee firsteopen("input.txt","r",stdin);firsteopen("output.txt","w",stdout);firsteopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

int gcd(int a, int b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
int pw(int a, int b, int p)
{
    if(b == 0)return 1;
    int t = pw(a, b / 2, p);
    if(b % 2)return (((a * t) % p) * t) % p;
    else return ((t * t) % p);
}

pair<int, int> rot(pair<int, int> x, pair<int, int> a)
{
    int u = x.first - a.first, v = x.second - a.second;
    return { a.first - v,a.second + u };
}
int distSq(pair<int, int> a, pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int check(pair<int, int>* x)
{
    pair<int, int> p1 = x[0], p2 = x[1], p3 = x[2], p4 = x[3];
    int d2 = distSq(p1, p2); // first from p1 to p2
    int d3 = distSq(p1, p3); // first from p1 to p3
    int d4 = distSq(p1, p4); // first from p1 to p4
    if(d2 && d3 && d4 && distSq(p2, p3) && distSq(p2, p4) && distSq(p3, p4));else return 0;
    // If lengths if (p1, p2) and (p1, p3) are same, then
    // following conditions must met to form a square.
    // 1) Square of length of (p1, p4) is same as twice
    // the square of (p1, p2)
    // 2) Square of length of (p2, p3) is same as twice the square of (p1, p2)

    if(d2 == d3 && 2 * d2 == d4 && 2 * d2 == distSq(p2, p3))
    {
        int d = distSq(p2, p4);
        return (d == distSq(p3, p4) && d == d2);
    }

    // The below two cases are similar to above case
    if(d3 == d4 && 2 * d3 == d2 && 2 * d3 == distSq(p3, p4))
    {
        int d = distSq(p2, p3);
        return (d == distSq(p2, p4) && d == d3);
    }
    if(d2 == d4 && 2 * d2 == d3 && 2 * d2 == distSq(p2, p4))
    {
        int d = distSq(p2, p3);
        return (d == distSq(p3, p4) && d == d2);
    }
    return 0;
}

void solve()
{
    pair<int, int> x[4], a[4];int ans = -1;
    for(int i = 0;i < 4;i++)
    {
        cin >> x[i].first >> x[i].second >> a[i].first >> a[i].second;
    }
    for(int i = 0;i < 256;i++)
    {
        pair<int, int> xz[4], az[4];
        for(int i = 0;i < 4;i++)
        {
            xz[i] = x[i];
            az[i] = a[i];
        }
        int p = i, c = 0;
        for(int i = 0;i < 4;i++)
        {
            int d = p % 4;
            c += d;
            for(int zz = 0;zz < d;zz++)xz[i] = rot(xz[i], az[i]);
            p /= 4;
        }
        if(check(xz))
        {
            if(ans == -1)ans = c;
            ans = min(c, ans);
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    firstee
#endif
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

