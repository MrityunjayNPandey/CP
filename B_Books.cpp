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
    int n, t, sum = 0, count = 0, j = 0, ans = 0, k=0;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (sum <= t)
        {
            sum += a[k];
            k++;
            count++;
            //cout<<"if"<<sum<<count<<endl;
            if (sum <= t)
            ans = max(ans, count);
            if(k==n)
            break;
        }
        else
        {
            sum -= a[j];
            j++;
            count--;
            ans = max(ans, count);
            i--;
            //cout<<"else"<<sum<<count<<endl;
        }
    }
    cout << ans;
}

int32_t main()
{
    ios;
    int Test = 1;
    //cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        cout << endl;
    }
}