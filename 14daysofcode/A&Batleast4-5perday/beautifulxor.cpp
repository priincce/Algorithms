#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      int a, b;
      cin>>a>>b;
      if(__builtin_clz(a)>__builtin_clz(b)){
            cout<<"-1\n";
      }else if(a==b){
            cout<<"0\n";
      }else{
            vi arr;
            for(int i=0;i<31;i++){
                  int x=(1<<i);
                  if(x<=a && (a&x)==0)a+=x, arr.pb(x);
            }
            for(int i=0;i<31;i++){
                  int x=(1<<i);
                  if(x<=a && (b&x)==0) arr.pb(x);
            }
            cout<<arr.size()<<"\n";
            for(auto i:arr)cout<<i<<" ";
            cout<<"\n";
      }
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