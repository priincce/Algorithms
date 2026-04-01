#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve() {
      int n, k, q;
      cin>>n>>k>>q;
      vector<int>a(n);
      for(int i=0; i<n; i++){
            int x;cin>>x;
            a[i]=(x<=q);
      }
      ll ans =0;
      int cur=0;
      for(int i=0;i<n; i++){
            if(a[i]){
                  cur++;
            }else{
                 if(cur >=k) ans+=(1LL*(cur-k+1)*(cur-k+2)/2);
                 cur=0;
            }
      }
      if(cur>=k) ans += 1LL*(cur-k+1)*(cur-k+2)/2;
      cout <<ans<<endl;
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int t=1;
      cin>>t;
      while(t--){
            solve();
      }
      return 0;
}