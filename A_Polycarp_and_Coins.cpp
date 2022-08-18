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
    int n;                                          // c1 = 0, c2 = 0, temp = 0;
    cin >> n;
    cout<<(n/3)+(n%3==1?1:0)<<' '<<(n/3)+(n%3==2?1:0);
}
int32_t main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
    // c2 = n / 4;
    // vector<int> a;
    // if (n % 2 != 0)
    // {
    //     c1 = 1;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (c1 <= ((n + 1) / 2))
    //     {
    //         if (c2 <= (n + 1) / 2 && c2 >= n / 4)
    //         {
    //             c2 = (n - c1) / 2;
    //             a.push_back(abs(c1 - c2));
    //             a.shrink_to_fit();
    //             if (temp > 0)
    //             {
    //                 if (a[temp] >= a[temp - 1])
    //                 {
    //                     break;
    //                 }
    //             }
    //             temp++;
    //         }
    //         c1 += 2;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // c1 -= 2, c2 = (n - c1) / 2;
    // cout << c1 << " " << c2;