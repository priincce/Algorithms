#include<bits/stdc++.h>
#define int long long
using namespace std;
int get(vector<int>&a){
      if(a.empty()) return 0;
      int  n= a.size();
      int ans=0, pos=n/2;

      for(int i=0;i<n;i++){
            ans+=abs(a[pos]-a[i])-abs(pos-i);
      }
      return ans;
}
void solve(){
      int n;
      cin>>n;
      vector<int>a, b;
      for(int i=1;i<=n; i++){
            char ch;
            cin>>ch;
            if(ch=='a')a.push_back(i);
            else b.push_back(i);
      }
      cout<<min(get(a), get(b))<<endl;

}
int32_t main(){
      int testcase=1;
      cin>>testcase;
      while(testcase--)solve();
      return 0;
}