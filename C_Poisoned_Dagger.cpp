#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define free                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;

int I;

void solve()
{
    int n, h;
    cin >> n >> h;
    int a[n];
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb(a[i]);
    }
    //    int t=n;
    // if(t<h)
    // {int k=0; t=0;
    // for(int i=0;; i++)
    //    {
    //        for(int i=0; i<n; i++)
    //           {
    //              if(i<n-1)
    //              {
    //               if(v[i]<a[i+1])
    //                 {
    //                     v[i]++;
    //                     t++;
    //                 }
    //              }
    //              else
    //              {v[i]++; t++;k++;}
    //           }
    //         if(t>=h)
    //         break;
    //    }
    // cout<<k;
    // }
    // else
    // cout<<1;
    vector<int> vd;
    for (int i = 1; i < n; i++)
    {
        vd.pb(a[i] - a[i - 1]);
    }
    sort(all(vd));
    int temp, p = n, k = 0, p1 = 0, temp1=0;
    for (int i = 0; i < vd.size(); i++)
    {
        temp = v[i] * p;
        for (int j = 0; j < i; j++)
        {
            temp += v[j];
            temp1 += v[j];
        }
        if (temp >= h)
        {
            p1 = i;
            k++;
            break;
        }
        p--;
    }
    if (k != 0)
    {
        int p2 = vd[p1]/2, ans=0;
        while (ans != h)
        {
            ans=0;
            if (p2< vd[p1 - 1])
            {
                for (int j = p1 - 1; j >= 0; j--)
                {
                    if(vd[j]>p2)
                        {
                            ans+=p2;
                        }
                    else
                        {
                            ans+=vd[j];
                        }
                }
                ans+=p2*p1;
            }
            else
                {
                    ans+=temp1;
                    ans+=p2*p1;
                }
            if(ans<h)
                {
                    p2=3*p2/2;
                }
            else
                {
                    p2/=2;
                }
        }
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        cout << endl;
    }
}