#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
      int pref=0;
      int suff=0;
      int best =0;
      int sum =0;
};
int n,q;
vector<Node>seg;
vector<int>arr;

Node operation(const Node&a, const Node&b){
      Node res;
      res.sum = a.sum+b.sum;
      res.pref = max(a.pref, a.sum + b.pref);
      res.suff = max(b.suff, b.sum + a.suff);
      res.best = max({a.best, b.best, a.suff + b.pref});
      return res;
}

void build(int i, int low, int high){
      if(low == high){
            seg[i].pref=arr[low];
            seg[i].suff= arr[low];
            seg[i].best = arr[low];
            seg[i].sum = arr[low];
            return;
      }
      int mid = low+(high-low)/2;
      build(i<<1, low, mid);
      build(i<<1|1, mid+1, high);
      seg[i]=operation(seg[i<<1], seg[i<<1|1]);
}
void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx].pref = seg[idx].suff = seg[idx].best = seg[idx].sum = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx, l, mid, pos, val);
    else
        update(2 * idx + 1, mid + 1, r, pos, val);
    seg[idx] = operation(seg[idx<<1], seg[idx<<1|1]);
}

int32_t main(){
      cin>>n>>q;
      arr.resize(n);
      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      seg.resize(4*n+5);
      build(1, 0, n-1);
      cout<<((seg[1].best<0)?0:seg[1].best)<<endl;
      for(int i=0; i<q;i++){
            int ind, val;
            cin>>ind>>val;
            update(1, 0, n-1,ind, val);
            cout<<((seg[1].best<0)?0:seg[1].best)<<endl;
      }
      return 0;
}
