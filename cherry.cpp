#include <bits/stdc++.h>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve()
{
    int n, max = 0, min = 0, minin = 0;
    cin >> n;
    vector<int> a(n);
    vector<int>::iterator itmax, itmin;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    max = *max_element(a.begin(), a.end());
    min = *min_element(a.begin(), a.end());
    itmax = find(a.begin(), a.end(), max);
    itmin = find(a.begin(), a.end(), min);
    min = *min_element(itmax, itmin);
    cout << max * min;
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