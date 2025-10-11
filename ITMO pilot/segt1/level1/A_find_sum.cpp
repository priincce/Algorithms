#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>seg;
ll operation(ll &a, ll &b){
      return a+b;
}

void build(ll index, ll low, ll high, vector<ll>&arr){
      if(low==high){
            seg[index]=arr[low];
            return;
      }
      
      ll mid =low + (high-low)/2;
      build(2*index+1, low, mid, arr);
      build(2*index+2, mid+1, high, arr);
      seg[index]=operation(seg[2*index+1], seg[2*index+2]);
}


ll query(ll left, ll right, ll low, ll high, ll index=0) {
    if (left > high || right < low) {
        return 0;
    }

    if (left <= low && high <= right) {
        return seg[index];
    }

    ll mid =low + (high-low)/2;
    ll l = query(left, right, low, mid, 2 * index + 1);
    ll r = query(left, right, mid + 1, high, 2 * index + 2);
    return l + r;
} 

void update(ll i, ll newVal,ll ind, ll low, ll high) {
    if (low == high) {
        seg[ind] = newVal; 
        return;
    }

    ll mid = (low + high) / 2;
    if (i <= mid)
        update(i, newVal, 2 * ind + 1, low, mid);
    else
        update(i, newVal, 2 * ind + 2, mid + 1, high);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}


void solve(){
      ll n,q;
      cin>>n>>q;
      vector<ll>arr(n);
      for(ll i=0;i<n;i++)cin>>arr[i];
      seg.resize(4*n,0);
      build(0, 0, n-1, arr);
      while(q--){
            ll t;
            cin >>t;
            if(t==1){
                  ll ind, val;
                  cin>>ind>>val;
                  update(ind,val,0,0, n-1);
            }else{
                  ll s,e;
                  cin>>s>>e;
                  e--;
                  cout<<query(s, e, 0, n-1)<<endl;
            }   
      }
}
int32_t main(){
      ll t=1;
      // cin >> t;
      while(t--){
            solve();
      }
      return 0;
}


