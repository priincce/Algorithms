#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin >> n;
      int dp[n+1]={0};
      dp[0]=1;
      for(int i=1;i<=n;i++){
            for(int d=1;d<=6;d++){
                  if(i-d >=0){
                        dp[i] +=dp[i-d];
                  }
            }
      }
      cout<<dp[n]<<endl;
      return 0;
}