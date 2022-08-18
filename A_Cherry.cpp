#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, max = 0, max2 = 0, max3 = 0, min = 0, minin = 0, j = 0;
    cin >> n;
    vector<int> a(n), c;
    vector<int>::iterator itmax;
    vector<int>::iterator itmax2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(a);
    max = *max_element(a.begin(), a.end());
    //min = *min_element(a.begin(), a.end());
    itmax = find(a.begin(), a.end(), max);
    a.erase(itmax, itmax + 1);

    // for (int i : a)
    // {
    //     cout << i;
    // }

    while (a.size() != 0)
    {
        //itmin = find(a.begin(), a.end(), min);
        max2 = *max_element(a.begin(), a.end());
        if (max2 == max3)
        {
            break;
        }
        //min = *min_element(a.begin(), a.begin());
        itmax2 = find(a.begin(), a.end(), max2);
        max3 = *min_element(itmax - a.begin(), (itmax2 + 1) - a.begin());
        c[j] = max * max3;
        j++;
        a.erase(itmax2, itmax2 + 1);
    }
    c.shrink_to_fit();
    cout << *max_element(c.begin(), c.end());
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