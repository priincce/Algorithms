

#include<bits/stdc++.h>
using namespace std;
vector<int> suffix_arr(string& s){
      int n= s.size();
      vector<pair<char, int>>a(n);
      for(int i=0;i<n;i++){
            a[i]={s[i], i};
      }
      sort(a.begin(), a.end());
      vector<int>c(n), p(n);
      for(int i=0;i<n;i++){
            p[i]= a[i].second;
      }
      c[p[0]]=0;
      for(int i=1;i<n;i++){
            c[p[i]]=c[p[i-1]];
            if(a[i].first != a[i-1].first)c[p[i]]++;
      }
      int k=0;
      while((1<<k)<n){
            vector<pair<pair<int, int>, int>>b(n);
            for(int i=0;i<n;i++){
                  b[i]={{c[i], c[(i+(1<<k))%n]}, i};
            }
            sort(b.begin(), b.end());
            for(int i=0;i<n;i++){
                  p[i]= b[i].second;
            }
            c[p[0]]=0;
            for(int i=1;i<n;i++){
                  c[p[i]]=c[p[i-1]];
                  if(b[i].first != b[i-1].first)c[p[i]]++;
            }
            k++;
      }
      return p;
}

vector<int> lcparr(const string &s, const vector<int>&p){
      int n = s.size();
      vector<int>rank(n), lcp(n-1, 0);

      for(int i=0;i<n;i++)rank[p[i]]=i;
      int k=0;
      for(int i=0;i<n; i++){
            if(rank[i]==n-1){
                  k=0;
                  continue;
            }
            int j= p[rank[i]+1];
            while(k+i<n && k+j<n &&s[i+k]==s[j+k]){
                  k++;
            }
            lcp[rank[i]]=k;
            if(k){
                  k--;
            }
      }
      return lcp;
}
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      string s, t;
      cin>>s>>t;
      string S = s+'#'+t+'$';

      vector<int>p=suffix_arr(S);
      vector<int>lcp= lcparr(S, p);

      int n= s.size();
      int best=0, start=0;
      for(int i=0;i<lcp.size();i++){
            bool a = p[i]<s.size();
            bool b = p[i+1]<s.size();
            if(a!= b){
                  if(lcp[i]> best){
                        start=p[i];
                        best = lcp[i];
                  }
            }
      }
      cout<<S.substr(start, best)<<"\n";

      return 0;
}


