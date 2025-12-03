#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
      ll n, k;
      cin>>n>>k;
            
      deque<ll>a(n);
      for(ll i=0; i<n; i++){
            cin>>a[i];
      }
      sort(a.begin(), a.end());
      ll sum=0, bonus=0;
      vector<ll>ans;
      
      while(!a.empty()){
            if(sum+a.back() >= k){
                  sum=(sum+a.back())%k;
                  bonus+=a.back();
                  ans.push_back(a.back());
                  a.pop_back();
            }else{
                  sum=(sum+a.front())%k;
                  ans.push_back(a.front());
                  a.pop_front();
            }
      }
      cout<<bonus<<"\n";
      for(auto&i: ans)cout<<i<<" ";
      cout<<"\n";
}
int main(){
      int test;
      cin>>test;
      while(test--){
            solve();
      }
      return 0;
}

