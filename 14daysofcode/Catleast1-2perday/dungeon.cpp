#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+5;
int n,m;
struct node{int b,c;}a[MAXN];
void solve(){
	cin>>n>>m;
	multiset<int> S;
	for(int i=1;i<=n;i++){
		int x;cin>>x;S.insert(x);
	}
	int ans=0;
	for(int i=1;i<=m;i++) cin>>a[i].b;
	for(int i=1;i<=m;i++) cin>>a[i].c;
	sort(a+1,a+m+1,[&](node x,node y){
		if((x.c==0)^(y.c==0)) return x.c>y.c;
		return x.b<y.b;
	});

	for(int i=1;i<=m;i++){
		auto it=S.lower_bound(a[i].b);
		if(it==S.end()) continue;
		int x=*it;S.erase(it);
		ans++;
		if(a[i].c) S.insert(max(a[i].c,x));
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
