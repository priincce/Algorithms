#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
void solve(){
      int n;
      cin>>n;
      int totalsec=0;
      int f=LLONG_MAX, s=LLONG_MAX;
      for(int i=0;i<n;i++){
            int m;
            cin>>m;
            vi a(m);
            for(int j=0;j<m; j++){
                  cin>>a[j];
            }
            sort(a.begin(), a.end());
            f=min(a[0], f);
            totalsec+=a[1];
            s=min(a[1], s);
            
      }
      cout<<totalsec-s+f<<"\n";
}
signed main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}