#include <bits/stdc++.h>
#define int long long
using namespace std;
struct trip{
      int l=-1,r=-1,ind=0;
};
bool compare(trip&a,trip&b){
      return a.r<b.r;
}
int n;
vector<int> seg;

void update(int pos, int i, int l, int r, int val) {
    if (l == r) {
        seg[i] = val;   
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(pos, i*2+1, l, mid, val);
    else update(pos, i*2+2, mid+1, r, val);
    seg[i] = seg[i*2+1] + seg[i*2+2];
}

int query(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;  
    if (ql <= l && r <= qr) return seg[i]; 
    int mid = (l + r) / 2;
    return query(i*2+1, l, mid, ql, qr) + query(i*2+2, mid+1, r, ql, qr);
}

void solve() {
    cin >> n;
    vector<trip> a(n, {-1, -1, 0});
    for (int i = 0, x; i < 2 * n; i++) {
        cin >> x;
        if (a[x-1].l == -1) a[x-1].l = i;
        else a[x-1].r = i;
        a[x-1].ind = x;
    }

    sort(a.begin(), a.end(), compare);
    seg.assign(8 * n, 0);
    vector<int> ans(n+1);

    for (int i = 0; i < n; i++) {
      ans[a[i].ind - 1] = query(0, 0, 2 * n - 1, a[i].l, a[i].r - 1);
      update(a[i].l, 0, 0, 2 * n - 1, 1);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            solve();
      }
      return 0;
}