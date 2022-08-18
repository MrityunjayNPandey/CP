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
unordered_map<int, int> visited;
unordered_map<int, vector<int>> adj_list;
map<pair<int, int>, int> adj_weight;
int parent = 0, ktd = 0;
void DFS(int current)
{
    visited[current]++;
    for (int next_vertex : adj_list[current])
        if (visited[next_vertex] == 0)
        {
            if (ktd % 2 == 0)
            {
                adj_weight[{current, next_vertex}] = 2;
                adj_weight[{next_vertex, current}] = 2;
            }
            else
            {
                adj_weight[{current, next_vertex}] = 5;
                adj_weight[{next_vertex, current}] = 5;
            }
            debug(ktd)
                ktd++;
            debug(next_vertex)
                DFS(next_vertex);
            ktd = 1;
        }
}

void solve()
{
    vector<pair<int, int>> vp;
    int n = 0, k = 0, ans = 0, t = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int p, q;
        cin >> p >> q;
        vp.pb({p, q});
        adj_list[p].push_back(q);
        adj_list[q].push_back(p);
        debug(p, q, vp, adj_list);
        if (adj_list[p].size() >= 3 || adj_list[q].size() >= 3)
        {
            t++;
        }
    }
    DFS(1);
    debug(visited) if (t > 0)
    {
        cout << -1;
    }
    else
    {
        debug(vp);
        for (int i = 0; i < vp.size(); i++)
        {
            cout << adj_weight[{vp[i].first, vp[i].second}] << " ";
        }
    }
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        visited.clear();
        adj_list.clear();
        adj_weight.clear();
        ktd=0;
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
