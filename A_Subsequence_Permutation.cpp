#include <bits/stdc++.h>
using namespace std;
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
    int n, k = 0; // temp = 0;
    cin >> n;
    char temp;
    vector<char> str1(n);
    vector<int>::iterator it;
    //vector<int>::size_type sz = str1.size();
    for (int i = 0; i < n; i++)
    {
        cin >> str1[i];
    }
    vector<char> str2(str1);
    sort(str1.begin(), str1.end());
    for (int i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
        {
            it = find(str2.begin(), str2.end(), str1[i]);
            temp = str2.at(it);
            str2.emplace(it, str2[i]);
            str2[i] = temp;
            k++;
        }
    }
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