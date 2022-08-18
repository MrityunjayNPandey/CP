#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

const int maxn = 5050;

pair <int, int> v[maxn];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[i] = make_pair(x, y);
  }

  sort(v, v + n);

  int h = -1;

  for (int i = 0; i < n; i++) {
    if (v[i].second < h) {
      h = v[i].first;
    } else {
      h = v[i].second;
    }
  }

  cout << h;

  return 0;
}