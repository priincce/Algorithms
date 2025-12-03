#include <bits/stdc++.h>
using namespace std;

//tail recursion
void fun(int x){
      if(x==0) return; 
      //termination condition 
      cout<<x<<" ";
      fun(x-1);
}
//head
void fun2(int x){
      if(x==0) return; 
      //termination condition 
      fun2(x-1);
      cout<<x<<" ";
}





int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);
      fun(4);
      cout<<"\n";
      fun2(6);
      
      return 0;
}