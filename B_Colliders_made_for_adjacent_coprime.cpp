// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define free freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << __LINE__ <<" "<< #x <<" = "; _print(x);
#else
#define debug(x...)
#endif
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void _print() {cerr << "\n";}
template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, m = 0, ans = 0;
    cin >> n >> m;
    map<int, int> mp;
    auto itr = mp.begin();
    for (int i = 0; i < m; i++)
    {
        char req;
        int num;
        cin >> req >> num;
        debug(req, num);
        debug(mp);
        if (req == '+')
        {
            if (mp[num] != 0)
            {
                cout << "Already on" << nl;
                continue;
            }
            itr = mp.find(num);
            mp[num]++;
            debug(*itr, mp);
            debug(prev(itr, 1)->ff);
            debug(next(itr, 1)->ff);
            debug(__gcd(num, prev(itr, 1)->ff));
            debug(__gcd(num, next(itr, 1)->ff));
            int p = 0;
            auto prev1 = prev(itr, 1)->ff;
            auto next1 = next(itr, 1)->ff;
            if (mp[prev1] != 0 && mp[next1] != 0)
            {
                if (__gcd(num, prev1) == 1 && __gcd(num, next1) == 1)
                {
                    debug("assd");
                    cout << "Success" << nl;
                    p++;
                }
            }
            else if (mp[prev1] != 0)
            {
                mp[next1];
                debug("assd") if (__gcd(num, prev1) == 1 || __gcd(num, prev1) == num)
                {
                    cout << "Success" << nl;
                    p++;
                }
            }

            else if (mp[next1] != 0)
            {
                debug("assd");
                debug(next1);
                if (__gcd(num, next1) == 1)
                {
                    cout << "Success" << nl;
                    p++;
                }
            }
            else
            {
                debug("assd");
                cout << "Success" << nl;
                p++;
            }
            if (mp[prev1] == 0 || mp[next1] == 0)
            {
                if (mp[prev1] == 0)
                    mp.erase(prev1);
                if (mp[next1] == 0)
                    mp.erase(next1);
            }
            if (p == 0)
            {
                if (__gcd(num, prev1) != 1 && __gcd(num, prev1) != num)
                {
                    debug(prev1);
                    cout << "Conflict with " << prev1 << nl;
                    mp.erase(num);
                    debug(*itr, mp);
                }
                else
                {
                    debug(*itr, mp);
                    cout << "Conflict with " << next1 << nl;
                    mp.erase(num);
                }
            }
        }
        else
        {
            if (mp[num] == 0)
            {
                cout << "Already off" << nl;
                continue;
            }
            else
            {
                cout << "Success" << nl;
                mp.erase(num);
            }
        }
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << nl;
        solve();
        // cout << endl;
    }
}