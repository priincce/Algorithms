#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, sum=0;
      cin>>n;
      vector<int>arr(7);
      for(int i=0;i<7;i++){
            cin>>arr[i];
            sum+=arr[i];
      }
      int left=n%sum;
      if(left ==0){
            left = sum;
            for(int i=0;i<7;i++){
                  if(sum-arr[i]<=0){
                        cout<<i+1<<"\n";
                        break;
                  }
                  sum-=arr[i];
            }
      }else{
            for(int i=0;i<7;i++){
                  if(left-arr[i]<=0){
                        cout<<i+1<<"\n";
                        break;
                  }
                  left-=arr[i];
            }
      }
      return 0;
}