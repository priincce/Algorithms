#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
pi maxSubArray(vector<int>& nums) {
      int local=0;
      int global=INT_MIN;
      int start=0, end=0, s=0, e=0;
      for(int i=0;i<nums.size();i++){
            int c=nums[i];
            local+=c;
            if(local>global){
                  global = local;
                  start = s;
                  end = i;
            }
            if(local < 0){
                  s=i+1;
                  local =0;
            }
      }
      return {start, end};
}

void solve(){
      int n;
      cin>>n;
      vi a(n);
      for(auto &i:a)cin>>i;
      pi ans= maxSubArray(a);
      cout<<ans.first<< " "<<ans.second<<endl;
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