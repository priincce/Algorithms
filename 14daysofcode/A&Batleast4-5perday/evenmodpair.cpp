#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      int n;
      cin>>n;
      vi a(n);
      for(int i=0;i<n;i++)cin>>a[i];
      // for(int i=0;i<n;i++)cout<<a[i]<<" ";
      for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                  if((a[j]%a[i])%2==0){
                        cout<<a[i]<<" "<<a[j]<<"\n";
                        return;
                  }

            }
      }
      cout<<-1<<"\n";
}
int main(){
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