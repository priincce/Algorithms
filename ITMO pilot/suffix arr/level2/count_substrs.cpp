#include<bits/stdc++.h>
using namespace std;
vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
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

      auto cmp = [&](const string &pat, int pos) {
            string suffix = s.substr(pos, min((int)pat.size(), n - pos));
            return suffix.compare(0, pat.size(), pat);
      };

      for(auto &pat:sbs){
            int m = pat.size();

            int l = 0, r = n - 1, lb = n;

            while (l <= r) {
                  int mid = (l + r) / 2;
                  if (cmp(pat, p[mid]) >= 0) {
                        lb = mid;
                        r = mid - 1;
                  }else{
                         l = mid + 1;
                  }
            }

            l = 0, r = n - 1;
            int ub = n;
            while (l <= r) {
                  int mid = (l + r) / 2;
                  if (cmp(pat, p[mid]) > 0) {
                  ub = mid;
                  r = mid - 1;
                  } else{
                         l = mid + 1;
                  }
            }

            int freq = max(0, ub - lb);
            cout << freq << "\n";
      }
    
      return 0;

}



