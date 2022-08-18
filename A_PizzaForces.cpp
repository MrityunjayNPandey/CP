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
    long long int n, m, o;
    cin >> n;
    if (n <= 6)
    {
        cout << 15;
    }
    else if (n % 2 == 0)
    {
        cout << n * 5 / 2;
    }
    else
    {
        cout << (n + 1) * 5 / 2;
    }
    // m = n / 10;
    // o = n % 10;
    // if (n == 11)
    // {
    //     cout << 30;
    // }
    // else if (n % 14 == 13 || n % 14 == 0)
    // {
    //     if (n % 14 == 13)
    //     {
    //         cout << ((n + 1) / 14) * 35;
    //     }
    //     else
    //         cout << n / 14 * 35;
    // }
    // else if (o == 0)
    // {
    //     cout << m * 25;
    // }
    // else if (n % 6 == 0 || n % 6 == 5)
    // {
    //     if (n % 6 == 5)
    //     {
    //         cout << ((n + 1) / 6) * 15;
    //     }
    //     else
    //         cout << n / 6 * 15;
    // }
    // else if (n % 8 == 0 || n % 8 == 7)
    // {
    //     if (n % 8 == 7)
    //     {
    //         cout << ((n + 1) / 8) * 20;
    //     }
    //     else
    //         cout << n / 8 * 20;
    // }
    // else if (n % 14 <= 10 && n >= 14 && n % 14 >= 5)
    // {
    //     if (n % 14 <= 6)
    //     {
    //         cout << n / 14 * 35 + 15;
    //     }
    //     else if (n % 14 <= 8)
    //     {
    //         cout << n / 14 * 35 + 20;
    //     }
    //     else if (n % 14 <= 10)
    //     {
    //         cout << n / 14 * 35 + 25;
    //     }
    // }
    // else if (o <= 6)
    // {
    //     cout << (m * 25) + 15;
    // }
    // else if (o <= 8)
    // {
    //     cout << (m * 25) + 20;
    // }
    // else if (o > 8)
    // {
    //     cout << (m + 1) * 25;
    // }
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}