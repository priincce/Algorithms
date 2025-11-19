#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
int n, k;

vi a;

void solve(){
      cin>>n>>k;
      a.resize(n);
      for(int i=0;i<n;i++)cin>>a[i];
      for(int i=0, x; i<k; i++){
            cin>>x; 
            int ub= upper_bound(a.begin(), a.end(), x)-a.begin();
            cout<<ub<<endl;
      }
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