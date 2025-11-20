#include <bits/stdc++.h>
#define int long long
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      int n, m;
      cin>>n>>m;
      vpi a(n);
      for(int i=0;i<n;i++){
            cin>>a[i].second;
      }
      for(int i=0;i<n;i++){
            cin>>a[i].first;
      }
      sort(a.begin(), a.end(), [](const pi&a, const pi&b){
            if (a.first != b.first)
                  return a.first < b.first;     
            return a.second > b.second;   
      });

      auto it = a.begin();
      ll cost=0;
      if(a[0].first <=m){
            cost+=m;
            int i=1;
            while(i<n && it != a.end()){
                  if(it->first > m){
                        int possible=it->second;
                        if(possible>= n-i){
                              cost+=(n-i)*m;
                              break;
                        }else{
                              cost+=possible*m;
                              i+=possible;
                              it++;
                        }
                  }else{
                       int possible=it->second;
                        if(possible>= n-i){
                              cost+=(n-i)*it->first;
                              break;
                        }else{
                              cost+=possible*it->first;
                              i+=possible;
                              it++;
                        } 
                  }
            }
      }else{
            cost=(ll)m*n;
      }
      cout << cost << "\n";
      
}
signed main(){
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