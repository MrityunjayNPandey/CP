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
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;
//number of disconnected components is the answer
// DFS, time complexity of O(V+E)
//Remember to clear the maps in main() if multiple test cases exist.
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> adj_list; //adjacency list
map<pair<int, int>, int> adj_weight; //to add weights on edges
int n = 0;
void DFS(int current)
{
    visited[current] = true;
    for(int i = 0; i < n; i++)
    {
        if((adj_list[i][0] == adj_list[current][0] || adj_list[i][1] == adj_list[current][1]) && visited[i] == false)
        {
            DFS(i);
        }
    }
}
void solve()
{
    int k = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj_list[i].push_back(x);
        adj_list[i].push_back(y);
    }
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
            DFS(i), ans++;
    }
    cout << ans - 1;
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;
        solve();
        cout << endl;
    }
}

