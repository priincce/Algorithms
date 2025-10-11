

#include<bits/stdc++.h>
using namespace std;
int main(){
      string s;
      cin>>s;
      int sz;
      cin>>sz;
      vector<string>sbs(sz);
      for(int i=0;i<sz;i++)cin>>sbs[i];
      s+='$';
      int n=s.size();
      vector<int>p(n), c(n);
      vector<pair<char, int>>a(n);
      for(int i=0;i<n;i++){
            a[i]={s[i], i};
      }
      sort(a.begin(), a.end());
      for(int i=0;i<n;i++){
            p[i]=a[i].second;
      }
      c[p[0]]=0;
      for(int i=1;i<n;i++){
            c[p[i]]=c[p[i-1]];
            if(a[i].first != a[i-1].first)c[p[i]]++;
      }
      int k=0;
      while((1<<k)<n){
            vector<pair<pair<int,int>, int>>b(n);
            for(int i=0;i<n;i++){
                  b[i]={{c[i], c[(i+(1<<k))%n]}, i};
            }
            sort(b.begin(), b.end());
            for(int i=0;i<n;i++){
                  p[i]=b[i].second;
            }
            c[p[0]]=0;
            for(int i=1;i<n;i++){
                  c[p[i]]=c[p[i-1]];
                  if(b[i].first != b[i-1].first)c[p[i]]++;
            }
            k++;
      }

      for(auto &pat:sbs){
            int m= pat.size();
            int l = 0, r = n - 1;
            bool found=false;
            while (l <= r) {
                  int mid = (l + r) / 2;
                  string suffix = s.substr(p[mid], min(m, n - p[mid]));
                  if (suffix.compare(0, m, pat) == 0) {
                        
                        found=true;
                        break;
                  }
                  if (suffix < pat) l = mid + 1;
                  else r = mid - 1;
            }
            cout<<(found?"Yes\n":"No\n");
      }
    
      return 0;

}


