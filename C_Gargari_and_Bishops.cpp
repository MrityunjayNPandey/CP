// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
	int n;
	cin >> n;
	int arr[n][n], d1[2 * n + 5] = {0}, d2[2 * n + 5] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			d1[i + j] += arr[i][j];
			d2[n - i + j] += arr[i][j];
		}
	}
	vector<int> ans(2, -1);
	map<int, pair<int, int>> mp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int p = (i + j) % 2;
			if (ans[p] < d1[i + j] + d2[n - i + j] - arr[i][j])
			{
				ans[p] = d1[i + j] + d2[n - i + j] - arr[i][j];
				mp[p] = {i, j};
			}
		}
	}
	cout << ans[0] + ans[1] << "\n";
	cout << mp[0].first + 1 << " " << mp[0].second + 1 << " " << mp[1].first + 1 << " " << mp[1].second + 1;
}
// clang-format off
int32_t main()
{
    ios;
    #ifdef SUBLIME
    free
    #endif
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}

