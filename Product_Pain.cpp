#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int q = a[i], r = a[i + 1];
        vector<int> v;
        v.push_back(r);
        for (int j = i + 2; j < n; j++)
        {
            int l = a[j];
            int mid = (a[i] + a[j]) / 2;
            auto iter = lower_bound(v.begin(), v.end(), mid);
            if (iter == v.end())
                iter--;
            r = *iter;
            int y = (q - r) * (r - l);
            if (iter != v.begin())
            {
                iter--;
                int x = (q - *iter) * (*iter - l);
                if (x > y)
                {
                    r = *iter;
                }
                iter++;
            }
            ans += (q - r) * (r - l);
            v.push_back(l);
        }
    }
    cout << ans;
}

int32_t main()
{
    int Test = 1;
    cin >> Test;
    for (int i = 1; i <= Test; i++)
    {
        solve();
        cout << endl;
    }
}
