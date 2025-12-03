#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      string s;
      cin>>s;
      for(int i=0; i<s.size()-1; i++){
            if(s[i]!='<' && s[i+1]!='>'){
                  cout<<-1<<"\n";
                  return;
            }
      }
      int l= count(s.begin(), s.end(),'<');
      int r = count(s.begin(), s.end(),'>');
      cout<<s.size()-min(l, r)<<"\n";
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