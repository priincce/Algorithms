#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
int maxSubarraySumCircular(vector<int>& nums, int k) {
      int n = nums.size();
      vector<ll>pref(n+1, 0);
      for(int i=0;i< nums.size(); i++){
            pref[i+1]= pref[i]+nums[i];
      }
      for(int i=0; i<=n; i++){
            while(!dq.empty() && )dq.pop_front();
            while(!dq.empty() && )dq.pop_back();
            dq.push_back(i);
      }
}

void solve(){
      int n;
      cin>>n;
      vi a(n);
      for(auto &i:a)cin>>i;
      
      cout<<maxSubarraySumCircular(a, 3)<<endl;
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