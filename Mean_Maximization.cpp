#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int max = 0, sum = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (max < a[i])
            {
                max = a[i];
            }
        }

        double x = max;

        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }

        double z = sum - max;
        double y = z / (n - 1);
        double s = x + y;

        cout << fixed << setprecision(12);
        cout << s << endl;
    }
    return 0;
}