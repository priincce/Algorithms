#include<bits/stdc++.h>
using namespace std; 
int main(){
int t;cin>>t;
while(t--){
 int n;
 cin>>n;
string s=" ";
for(int i=0;i<n;i++){
  char x;cin>>x;
  s.push_back(x);
}

int ans=0;
for(int i=1;i<n;i++)ans+=(s[i] != s[n]);
cout<<ans<<"\n";
}
return 0;
}