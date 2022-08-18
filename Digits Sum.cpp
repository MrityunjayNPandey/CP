#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cout << m / 10;
    }
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}