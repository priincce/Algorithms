#include<bits/stdc++.h>
using namespace std;
int n;
int unique_subseq_naive(int ind, string& cur, unordered_set<string>&st, string&s){
      //[Naive Approach] - Generating All Subsequences - O(2 ^ n) Time and O(2 ^ n) Space
      if(ind==n){
            st.insert(cur);
            return;
      }
      unique_subseq_naive(ind+1, cur, st, s);
      cur.push_back(s[ind]);
      unique_subseq_naive(ind+1, cur, st, s);
      cur.pop_back();
}
int solve_dp(string&s){
      vector<int>dp(n+1, 0), last(26, -1);
      dp[0] = 1;
      for(int i=1;i<=n;i++){
            dp[i]=2*dp[i-1];
            if(last[s[i-1]-'a'] != -1){
                  dp[i]-=dp[last[s[i-1]-'a']];
            }
            last[s[i-1]-'a']=i-1;
      }
      return dp[n];
}
int optimal(string&s){
      vector<int>last(26, -1);
      int res =1;
      for(int i=1;i<=n;i++){
            int curr = 2*res-last[s[i-1]-'a'];
            last[s[i-1]-'a']= res;
            res = curr;
      }
      return res;
}
int unique_subseq(string &s){

}
int main(){
      string s;
      n = s.size();
      int ans = unique_subseq(s);
      cout<<ans<<"\n";
      return 0;
}