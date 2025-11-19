#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back


void solve(){
    int n; 
    string s;
    cin >> n >> s;
    vector<int> pos;
    for(int i = 0; i < n; i++) if(s[i] == '0') pos.push_back(i + 1);

      cout << (int)pos.size() << '\n';
      for(auto& z : pos) cout << z << ' ';

      cout << '\n';
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