// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef joKer
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

                    // do something, stay focused
                    // look for stupid bugs
                    // guess, slow, stress
                    // don't overgeneralize
                    // don't rush
                        
                    // 1. Understand the problem
                    // 2. Devise a plan
                    // 3. Carry out the plan
                    // 4. Look back
                        
                    // don't waste time on standings
                        
                    // SOLVE THE PROBLEM OR DIE TRYING
                    // THE SOLUTION IS ALWAYS SIMPLE
                    // THE CODE IS ALWAYS SHORT

// clang-format on

// DFS, time complexity of O(V+E)
// Remember to clear the maps in main() if multiple test cases exist.
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> adj_list; // adjacency list
map<pair<int, int>, int> adj_weight;      // to add weights on edges
unordered_map<int, int> mp;
void DFS(int l, int r)
{
    if (l <= r)
    {
        if (l == r)
        {
            adj_weight[{l, r}] = l;
            return;
        }
        for (int i = l; i <= r; i++)
        {
            if (mp[i] == 0 || mp[i] == 1)
            {
                if (l != 1)
                {
                    adj_weight[{l + 1, r}] = i;
                }
                else
                {
                    adj_weight[{l, r - 1}] = i;
                }
                DFS(1, i - 1);
                DFS(i + 1, r);
                break;
            }
            mp[i]--;
        }
    }
}

void solve()
{
    int n = 0, k = 0, ans = 0;
    vector<int> v;
    vector<pair<int, int>> vp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        adj_list[p].pb(q);
        adj_list[q].pb(p);
        sort(all(adj_list[p]));
        sort(all(adj_list[q]));
        v.pb(q - p);
        mp[p]++;
        mp[q]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            adj_weight[{1, 6}] = i;
            DFS(1, i - 1);
            DFS(i + 1, n);
            break;
        }
    }
    debug(adj_weight)
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
