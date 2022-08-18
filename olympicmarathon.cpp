#include <bits/stdc++.h>
using namespace std;
void marathon()
{
    int n, m = 0, p = 0, q = 1, race = 0, maxcom = 0;
    cin >> n;
    int pq[n][5], temp[n], r[q][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> pq[i][j];
        }
    }
    while (race < 5)
    {
        for (int i = 0; i < n; i++)
        {
            temp[i] = pq[i][race];
        }
        m = sizeof(temp) / sizeof(temp[0]);
        p = *min_element(temp, temp + m); //to find minimum element

        //cout << "min element :" << p << endl;

        for (int i = 0; i < n; i++)
        {
            if (p == temp[i])
            {
                r[q][race] = i;
                if (maxcom < q)
                {
                    maxcom = q;
                }
                q++;
            }
        }
        q = 0;
        race++;
    }
    int ft = 5, finaltemp[ft];
    p = 0;
    if (maxcom != 0)
    {
        ft = maxcom * 5, finaltemp[ft];
        for (int i = 0; i < maxcom; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                finaltemp[p] = r[i][j];
                p++;
            }
        }
    }
    else
    {
        for (int j = 0; j < 5; j++)
            finaltemp[j] = r[0][j];
    }

    // for (int i = 0; i < ft; i++)
    // {
    //     cout << finaltemp[i];
    // }
    // cout << endl;

    m = sizeof(finaltemp) / sizeof(finaltemp[0]), p = 1;
    int pi[maxcom], t = 0, final = 0, final1 = 0;
    sort(finaltemp, finaltemp + m);
    for (int i = 0; i < ft; i++)
    {
        if (finaltemp[i] == finaltemp[i + 1])
        {
            pi[t] = p;
            p++;
            if (pi[t] == 3)
            {
                final = finaltemp[i];
                final1++;
                break;
            }
        }
        else
        {
            t++;
            p = 0;
        }
    }
    if (final1 != 0)
    {
        cout << final + 1; // << endl;
    }
    else
    {
        cout << "-1"; // << endl;
    }
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        marathon();
        cout << endl;
    }
}