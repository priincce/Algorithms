#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first
#define pi std::pair<int , int>
#define pl std::pair<ll, ll>
#define vi std::vector<int>
#define vpi std::vector<pi>
#define vl std::vector<ll>
#define vpl std::vector<pl>
const int M=1e9+7;

inline std::string binary(int n){
      if(n==0)return "0";
      std::string s = std::bitset<64>(n).to_string();
      return s;
}
inline std::string bin(int n){
      if(n==0)return "0";
      std::string s = std::bitset<64>(n).to_string();
      return s.substr(s.find('1'));
}
inline ll expo(ll a, ll b){
      if(b==0) return 1;
      ll res =1LL, val=a;
      while(b>0){
            if(b&1){
                  res=((val%M)*(val%M))%M;
            }
            val=((val%M)*(val%M))%M;
            b>>=1;
      }
      return res;
}
inline ll lcm(ll a, ll b){
      return (ll)(a*std::gcd(a, b))/b;
}



int main(){

}