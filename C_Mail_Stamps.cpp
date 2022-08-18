/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 30-04-2022 01:10:13
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

// DFS, time complexity of O(V+E)
//Remember to clear the maps in main() if multiple test cases exist.
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> adj_list; //adjacency list
map<pair<int, int>, int> adj_weight; //to add weights on edges
void DFS(int current)
{
    visited[current] = true;
    cout << current << " ";
    for(int next_vertex : adj_list[current])
    {
        if(!visited[next_vertex])
        {
            DFS(next_vertex);
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        mp[temp1]++, mp[temp2]++;
        adj_list[temp1].pb(temp2);
        adj_list[temp2].pb(temp1);
    }
    for(auto i : mp)
    {
        if(i.second == 1)
        {
            k = i.first;
            break;
        }
    }
    debug(adj_list)
    DFS(k);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

