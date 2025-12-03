#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int main(){
int t;cin>>t;
while(t--){

      ll n, ans=0, maxi=0;
      cin>>n;
      vector<ll>a(n+1);
      for(int i=0;i<n;i++)
      {
        cin>>a[i];
        maxi=max(a[i],maxi);
      }
      a[n] = a[0];
      for(int i=0;i<n;i++){
            ans+=max(a[i],a[i+1]);
      }
      ans-=maxi;
      cout<<ans<<endl;
}
return 0;
}