#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long

void solve(){
     string n;
     int j, k;
     cin>>n>>j>>k;
     string s1, s2;
     int i=1;
     if (i == j) s1 = n;
     if (i == k) s2 = n;


      while (next_permutation(n.begin(), n.end())) {
      i++;
      if (i == j) s1 = n;
      if (i == k) s2 = n;
      }
     int A=0;
     for(int end=0;end<n.size();end++){
      if(s1[end]==s2[end]){
            A++;
      }
     }
     cout<<A<<"A"<<n.size()-A<<"B"<<endl;
      
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