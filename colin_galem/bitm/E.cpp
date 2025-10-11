#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
/// @brief this question is only for ^ operator but added & and |
void solve_or(){
      ll l, r;
      cin>>l>>r;
      if(l==r){
            cout<<l<<endl;
      }else{
            ll msb= 63-__builtin_clzll(l^r);
            cout<<(1<<(msb+1))-1<<endl;
      }
}
void solve_and(){
      ll l, r;
      cin>>l>>r;
      cout<<r<<endl;
}
void solve_xor(){
      ll l, r;
      cin>>l>>r;
      if(l==r){
            cout<<0<<endl;
      }else{
            ll msb= 63-__builtin_clzll(l^r);
            cout<<(1LL<<(msb+1))-1<<endl;
      }
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            solve_xor();
      }
      return 0;
}