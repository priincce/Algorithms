#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
      ll w, h, n;
      cin>>w>>h>>n;
      ll low =1 , high = 1, ans;

      while ((high / w) * (high / h) < n) {
            high *= 2;
      }
      ans = high;
      
      while(low<=high){
            ll mid=(low+high)/2;
            ll cnt = (mid/w)*(mid/h);
            if(cnt>= n){
                  ans=mid;
                  high=mid-1;
            }else{
                  low=mid+1;
            }
      }
      cout<<ans<<endl;
}
int main(){
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