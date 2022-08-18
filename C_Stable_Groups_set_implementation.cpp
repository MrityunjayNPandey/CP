#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k, potset = 1, x = 0, sureset = 1, tempk = 0, o = 0, p = 0, enter, bitr, citr, bsize = 0;
    double temp = 0;
    cin >> n >> k >> x;
    tempk = k;
    set<long long, greater<long long>> a;
    set<long long, greater<long long>>::iterator itr;
    priority_queue<long long, vector<long long>, greater<long long>> bq;
    for (int i = 0; i < n; i++)
    {
        cin >> enter;
        a.insert(enter);
    }
    for (itr = a.begin(); itr != --a.end(); itr++)
    {
        bitr = *(++itr);
        citr = *(--itr);
        bq.push(citr - bitr);
    }
    priority_queue<long long, vector<long long>, greater<long long>> b(bq);
    bsize = bq.size();
    for (int i = 0; i < bsize; i++)
    {
        if (bq.top() > x)
        {
            potset++;
        }
        bq.pop();
    }
    if (k != 0)
    {
        for (int i = 0; i < bsize; i++)
        {
            temp = b.top() / (k + 1);
            if (tempk == 0)
            {
                break;
            }
            else if (temp <= x && b.top() > x)
            {
                if (b.top() % x != 0)
                {
                    p = (b.top() / x) + 1;
                }
                else
                {
                    p = b.top() / x;
                }
                o = p - 1;
                tempk -= o;
                if (tempk >= 0)
                {
                    potset--;
                }
            }
            b.pop();
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
    while (t--)
    {
        solve();
        cout << endl;
    }
}