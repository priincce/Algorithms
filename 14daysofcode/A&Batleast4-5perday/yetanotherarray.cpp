#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long


vector<int> primes = {
    2, 3, 5, 7,
    11, 13, 17, 19,
    23, 29,
    31, 37,
    41, 43, 47,
    53, 59,
    61, 67,
    71, 73, 79,
    83, 89,
    97,
    101, 103, 107, 109,
    113,
    127,
    131, 137, 139,
    149, 151
};

void solve(){
      ll n;
      cin>>n;
      vector<ll>arr(n);
      for(int i=0;i<n;i++)cin>>arr[i];
      for(auto p:primes){
            if(any_of(arr.begin(),arr.end(),[&](ll x){return x%p;})){
                  cout<<p<<"\n";
                  return ;
            }
      }
      cout<<-1<<endl;
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