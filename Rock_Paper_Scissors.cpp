#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char S = ' ', R = ' ', P = ' ';
    string res;
    for (int i = n - 1; i > -1; i--)
    {
        if (s[i] == 'S')
        {
            if (R == ' ')
            {
                res += string(1, s[i]);
                S = 'S';
            }
            else
            {
                res += string(1, R);
                S = R;
            }
        }
        else if (s[i] == 'P')
        {
            if (S == ' ')
            {
                res += string(1, s[i]);
                P = 'P';
            }
            else
            {
                res += string(1, S);
                P = S;
            }
        }
        else
        {
            if (P == ' ')
            {
                res += string(1, s[i]);
                R = 'R';
            }
            else
            {
                res += string(1, P);
                R = P;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << res;
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