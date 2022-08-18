// #include<bits/stdc++.h>
// using namespace std;
// #define pb push_back
// #define int long long
// #define all(x) x.begin(),x.end()
// #define rall(x) x.rbegin(),x.rend()
// #define LOG(n) 31 - __builtin_clz(n)
// #define nl  "\n"
// #define ok  cout<<"OK\n"
// #define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
// #define ff first
// #define ss second
// typedef pair<int,int> pii;
// const long long INF = 1ll << 32;
// const long long MAX_N = 1e6 + 7;
// const long long MOD = 998244353;
// const long long mod = 998244353;

// int I;

// void solve()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     map<int , int> mp;
//     int l1 = 1 , l2 = 1;
//     for(int i = 0 ; i<n ; i++) {
//         cin>>a[i];
//         if(mp[a[i]] == 1) {
//             l1 = (l1 * a[i]) / __gcd(a[i] , l1);
//         }
//         l2 = (l2 * a[i]) / __gcd(a[i] , l2);
//         mp[a[i]]++;
//     }
//     cout<<l1+l2;

// }

// int32_t main()
// {
//     ios;
//     int Test = 1;
//     //cin>>Test;
//     for(I = 1 ; I<=Test ;  I++)
//     {
//         solve();
//     }

// }
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
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    int l1 = 1, l2 = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] == 2)
        {
            l1 = (l1 * a[i]) / __gcd(a[i], l1);
        }
    }
    sort(a, a + n);
    for (int i = n - 2; i >= 0; i--)
    {
        if (mp[a[i]] == 2)
        {
            cout << a[n - 1] + l1;
            return;
        }
        if (a[n - 1] % a[i] != 0)
        {
            l1 = (l1 * a[i]) / __gcd(a[i], l1);
            cout << a[n - 1] + l1;
            return;
        }
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    //cin>>Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
    }
}