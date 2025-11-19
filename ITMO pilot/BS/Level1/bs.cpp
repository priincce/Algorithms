#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
int n, k;

vi a;
bool present(int x){
      int low =0, high = n-1;
      while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]==x)return true;
            else if(a[mid]> x){
                  high=mid-1;
            }else{
                  low = mid+1;
            }
      }
      return false;
}
void solve(){
      cin>>n>>k;
      a.resize(n);
      for(int i=0;i<n;i++)cin>>a[i];
      for(int i=0, x; i<k; i++){
            cin>>x;
            cout<<(present(x)?"YES":"NO")<<endl;
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