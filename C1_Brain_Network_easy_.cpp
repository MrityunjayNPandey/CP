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
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> adj_list;
int parent = 0, ktd = 0;
void DFS(int current)
{

    visited[current] = true;
    for (int next_vertex : adj_list[current])
        if (!visited[next_vertex])
        {
            DFS(next_vertex);
        }
}

void solve()
{
    bool f = 1;
    int n = 0, k = 0, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int t, p;
        cin >> t >> p;
        adj_list[t].push_back(p);
        adj_list[p].push_back(t);
    }
    if (k != n - 1)
        f = 0;
    debug(f, adj_list);
    DFS(1);
    debug(visited) for (int i = 1; i <= n; ++i) if (!visited[i])
        f = 0;
    if (f)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
