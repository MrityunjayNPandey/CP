/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-02-2025 08:09:00
 **/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define print(x)
#define dclear(x)
#endif
#define free                                                                   \
    freopen("input.txt", "r", stdin);                                          \
    freopen("output.txt", "w", stdout);                                        \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_map;
#define int long long

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<vector<int>> vv(n, vector<int>(m, 0));
    for (auto &v : vv) {
        for (auto &i : v) {
            cin >> i;
        }
    }
    vv[0][0] = -1e9;
    pair<int, int> coordinate = {0, 0};
    for (int i = 0; i < str.length(); i++) {
        auto &[l, r] = coordinate;
        if (str[i] == 'D') {
            l = l + 1;
        } else {
            r = r + 1;
        }
        vv[l][r] = -1e9;
    }
    cnt = n + m - 1;
    int desiredSum = 0;

    vector<pair<int, set<int>>> row, column;
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        set<int> st;
        for (int j = 0; j < m; j++) {
            if (vv[i][j] == -1e9) {
                st.insert(j);
            } else {
                rowSum += vv[i][j];
            }
        }
        row.push_back({rowSum, st});
    }
    for (int j = 0; j < m; j++) {
        int colSum = 0;
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (vv[i][j] == -1e9) {
                st.insert(i);
            } else {
                colSum += vv[i][j];
            }
        }
        column.push_back({colSum, st});
    }
    debug(row, column);

    k = 100;

    while (cnt) {
        debug(cnt);
        for (int i = 0; i < n && cnt; i++) {
            auto &[l, r] = row[i];
            if (r.size() == 1) {
                // debug(row[i]);
                int index = *r.begin();
                vv[i][index] = desiredSum - l;
                r.erase(index);
                l += vv[i][index];

                // debug(row[i]);
                auto &[colSum, colBlanks] = column[index];
                // debug(column[index]);
                colSum += vv[i][index];
                colBlanks.erase(i);
                // debug(column[index]);

                cnt--;
            }
        }

        for (int j = 0; j < m && cnt; j++) {
            auto &[l, r] = column[j];
            if (r.size() == 1) {
                // debug(column[j]);
                int index = *r.begin();
                vv[index][j] = desiredSum - l;
                r.erase(index);
                l += vv[index][j];
                // debug(column[j]);

                auto &[rowSum, rowBlanks] = row[index];
                // debug(row[index]);

                rowSum += vv[index][j];
                rowBlanks.erase(j);

                // debug(row[index]);

                cnt--;
            }
        }
        debug(row, column);

        debug(vv);
    }

    debug(row, column);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for (int I = 1; I <= Test; I++) {
        dclear(I);
        solve();
    }
}
