#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pp pop_back
#define umap unordered_map
#define uset unordered_set
#define sort(arr) sort(all(arr))
#define mini(arr) (*min_element(all(arr)))
#define maxi(arr) (*max_element(all(arr)))
#define lb(arr, x) (lower_bound(all(arr), (x)) - (arr).begin())
#define ub(arr, x) (upper_bound(all(arr), (x)) - (arr).begin())
template <typename Iterator>
void input(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) cin >> *it;
}
template <typename Iterator>
void output(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) cout << *it << ' ';
    cout << '\n';
}
const int MAXN = 1e5;
ll fact[MAXN + 1], invFact[MAXN + 1];
bool prime[MAXN + 1];
const int MOD = 1e9 + 7;
ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
void precompute_factorial() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modExp(fact[i], MOD - 2, MOD);
    }
}
ll nCr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}
ll nPr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll extd_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){ x=1; y=0; return a; }
    ll x1,y1;
    ll g = extd_gcd(b,a%b,x1,y1);
    x = y1; y = x1 - (a/b)*y1;
    return g;
}
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
// Modular inverses
ll modInverseFermat(ll a, ll m) { return modExp(a, m-2, m); }
ll modInverseEEA(ll a, ll m) {
    ll x, y;
    ll g = extd_gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}
void sieve(int n){
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i) prime[j]=false;
        }
    }
}
ll chineseRemainder(const vector<int> &arr,const vector<int> &moduli){
    int n = arr.size(); ll M=1;
    for(int i=0;i<n;i++) M*=moduli[i];
    ll x=0;
    for(int i=0;i<n;i++){
        ll Mi = M/moduli[i];
        ll yi = modInverseFermat(Mi,moduli[i]);
        x = (x + (ll)arr[i]*Mi%M*yi%M) % M;
    }
    return (x+M)%M;
}

int lis(vector<int>&arr, int ind){
      /* driver
      int n;
      cin>>n;
      vector<int>arr;
      input(all(arr));
      int res = 1;
      for (int i = 1; i < n; i++)
            res = max(res, lis(arr, i));
      cout<<res<<;
      
      */
      if(ind==0) return 1;
      
      int ans = 1;
      for(int prev = 0; prev<ind; prev++){
            if(arr[prev]<arr[ind]){
                  ans = max(ans, 1+lis(arr,prev));
            }
      }
      return ans;
}
int count_lis_tab(vector<int>&arr){
      int n=arr.size();
      int ans=1;
      vector<int> dp(n, 1), cnt(n,1);
      for(int i=1;i<n;i++){
            for(int prev=0;prev<i; prev++){
                  if(arr[i]>arr[prev]){
                        if(dp[i]<dp[prev]+1){
                              dp[i]=1+dp[prev];
                              cnt[i]=cnt[prev];
                        }else if(dp[i] == dp[prev]+1){
                              cnt[i]+=cnt[prev];
                        }
                  }
            }
            ans= max(dp[i], ans);
      }
      int res=0;
      for(int i=0;i<n;i++){
            if(ans==dp[i]){
                  res+=cnt[i];
            }
      }
      return res;
}
// int opt_(vector<int>&arr){
//       int n= arr.size();
//       vector<int>ans;
//       ans.push_back(arr[0]);
//       for(int i=1;i<n;i++){
//             if(arr[i]>ans.back()){
//                   ans.push_back(arr[i]);
//             }else{
//                   int index = lb(ans,arr[i]);
//                   ans[index]= arr[i];
//             }
//       }
//       return ans.size();
// }
void solve(){
      
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