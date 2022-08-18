#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m = 0;
    cin >> m;
    if (m % 10 == 9)
    {
        m++;
    }
    cout << m / 10 << endl;
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