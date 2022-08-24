#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], st[2000005];
void update(int id, int l, int r, int pos, int val) {
   if(pos < l || r < pos)
      return;
   if(l == r) {
      st[id] = val;
      return;
   }
   int mid = (l + r) / 2;
   update(2 * id, l, mid, pos, val);
   update(2 * id + 1, mid + 1, r, pos, val);
   st[id] = min(st[2 * id], st[2 * id + 1]);
}
int get(int id, int l, int r, int u, int v) {
   if(v < l || r < u)
      return INT_MAX;
   if(u <= l && r <= v)
      return st[id];
   int mid = (l + r) / 2;
   int x = get(2 * id, l, mid, u, v);
   int y = get(2 * id + 1, mid + 1, r, u, v);
   return min(x, y);
}
int main() {
//   freopen("LOCO.inp", "r", stdin);
//   freopen("LOCO.out", "w", stdout);
   cin >> n >> k;
   for(int i = 1; i <= n; i++)
      cin >> a[i];
   for(int i = 1; i <= k; i++)
      update(1, 1, n, i, a[i]);
   for(int i = k + 1 ; i <= n; i++) {
      int val = get(1, 1, n, i - k, i - 1) + a[i];
      update(1, 1, n, i, val);
   }
   cout << get(1, 1, n, n - k + 1, n);
}
