#include <bits/stdc++.h>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve()
{
    int n, k, potset = 1, x = 0, sureset = 1, tempk = 0, o = 0, p = 0;
    float temp = 0;
    cin >> n >> k >> x;
    tempk = k;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    //display(a);
    for (int i = 0; i < n - 1; i++)
    {
        b.push_back(a[i + 1] - a[i]);
        b.shrink_to_fit();
    }
    sort(b.begin(), b.end());
    //display(b);
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] > x)
        {
            potset++;
        }
    }
    //cout << potset << endl;
    //potset--;
    if (k != 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            // cout << "runnin" << tempk << endl;
            temp = b[i] / (k + 1);
            // cout << b[i] << " " << k << " " << temp << " " << x << endl;
            if (tempk == 0)
            {
                // cout << "runnin" << endl;
                break;
            }
            else if (temp <= x && b[i] > x)
            {
                // cout << "runnin" << endl;
                if (b[i] % x != 0)
                {
                    p = (b[i] / x) + 1;
                }
                else
                {
                    p = b[i] / x;
                }
                o = p - 1;
                tempk -= o;
                if (tempk >= 0)
                {
                    potset--;
                }
            }
        }
    }
    if (n == 1)
        cout << 1;
    else
        cout << potset;
}
int32_t main()
{
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}