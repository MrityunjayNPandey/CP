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
    int xk, yk, xr1, yr1, xr2, yr2;
    cin >> xk >> yk;
    cin >> xr1 >> yr1 >> xr2 >> yr2;
    if (xk != 1 && xk != 8 && yk != 1 && yk != 8)
        cout << "NO";
    else if ((abs(xk - xr1) == 1 && abs(yk - yr1) == 1) || (abs(xk - xr2) == 1 && abs(yk - yr2) == 1))
        cout << "NO";
    else
    {
        string ans = "NO";
        if (yk == 1)
        {
            if (xk != 1 && xk != 8)
            {
                if (yr1 == 2)
                {
                    if (xr1 != xr2 && xr2 != xk + 1 && xr2 != xk - 1)
                        ans = "YES";
                }
                else if (yr2 == 2)
                {
                    if (xr1 != xr2 && xr1 != xk + 1 && xr1 != xk - 1)
                        ans = "YES";
                }
            }
            else if (xk == 1 || xk == 8)
            {
                if (yr1 == 2)
                {
                    if (xr1 != xr2 && xr2 != xk + 1 && xr2 != xk - 1)
                        ans = "YES";
                }
                else if (yr2 == 2)
                {
                    if (xr1 != xr2 && xr1 != xk + 1 && xr1 != xk - 1)
                        ans = "YES";
                }
                else if (xr1 == 2 && xk == 1)
                {
                    if (yr1 != yr2 && yr2 != 2)
                        ans = "YES";
                }
                else if (xr2 == 2 && xk == 1)
                {
                    if (yr1 != yr2 && yr1 != 2)
                        ans = "YES";
                }
                else if (xr1 == 7 && xk == 8)
                {
                    if (yr1 != yr2 && yr2 != 2)
                        ans = "YES";
                }
                else if (xr2 == 7 && xk == 8)
                {
                    if (yr1 != yr2 && yr1 != 2)
                        ans = "YES";
                }
            }
        }
        else if (yk == 8)
        {
            if (xk != 1 && xk != 8)
            {
                if (yr1 == 7)
                {
                    if (xr1 != xr2 && xr2 != xk + 1 && xr2 != xk - 1)
                        ans = "YES";
                }
                else if (yr2 == 7)
                {
                    if (xr1 != xr2 && xr1 != xk + 1 && xr1 != xk - 1)
                        ans = "YES";
                }
            }
            else if (xk == 1 || xk == 8)
            {
                if (yr1 == 7)
                {
                    if (xr1 != xr2 && xr2 != xk + 1 && xr2 != xk - 1)
                        ans = "YES";
                }
                else if (yr2 == 7)
                {
                    if (xr1 != xr2 && xr1 != xk + 1 && xr1 != xk - 1)
                        ans = "YES";
                }
                else if (xr1 == 2 && xk == 1)
                {
                    if (yr1 != yr2 && yr2 != 7)
                        ans = "YES";
                }
                else if (xr2 == 2 && xk == 1)
                {
                    if (yr1 != yr2 && yr1 != 7)
                        ans = "YES";
                }
                else if (xr1 == 7 && xk == 8)
                {
                    if (yr1 != yr2 && yr2 != 7)
                        ans = "YES";
                }
                else if (xr2 == 7 && xk == 8)
                {
                    if (yr1 != yr2 && yr1 != 7)
                        ans = "YES";
                }
            }
        }
        else if (xk == 8)
        {
            if (yk != 1 && yk != 8)
            {
                if (xr2 == 7)
                {
                    if (yr1 != yr2 && yr1 != yk + 1 && yr1 != yk - 1)
                        ans = "YES";
                }
                else if (xr1 == 7)
                {
                    if (yr1 != yr2 && yr2 != yk + 1 && yr2 != yk - 1)
                        ans = "YES";
                }
            }
        }
        else if (xk == 1)
        {
            if (yk != 1 && yk != 8)
            {
                if (xr2 == 2)
                {
                    if (yr1 != yr2 && yr1 != yk + 1 && yr1 != yk - 1)
                        ans = "YES";
                }
                else if (xr1 == 2)
                {
                    if (yr1 != yr2 && yr2 != yk + 1 && yr2 != yk - 1)
                        ans = "YES";
                }
            }
        }
        cout << ans;
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
        cout << "\n";
    }
}
