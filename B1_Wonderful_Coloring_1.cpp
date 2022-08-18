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
    int j = 0, temp = 0, red = 0;
    string str;
    cin >> str;
    vector<int> a(str.length(), 1);
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == str[i + 1])
        {
            a[j] += 1;
        }
        else
        {
            j++;
        }
    }
    a.resize(j);
    a.shrink_to_fit();
    sort(a.begin(), a.end(), greater<int>());
    //display(a);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 2)
        {
            temp++;
        }
        else
        {
            break;
        }
    }
    if (temp >= 2)
    {
        red = temp;
        if ((a.size() - temp) % 2 == 0)
        {
            red += (a.size() - temp) / 2;
        }
        else
        {
            red += (a.size() - temp - 1) / 2;
        }
    }
    else
    {
        if ((a.size() - temp + 2 * temp) % 2 == 0)
        {
            red += (a.size() - temp + 2 * temp) / 2;
        }
        else
        {
            red += (a.size() - temp + 2 * temp - 1) / 2;
        }
    }
    cout << red;
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