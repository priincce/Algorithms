#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pi>

void countSort(vector<int> &p, vector<int> &c){
    int n = p.size();
    vector<int> cnt(n);
    for(auto x: c) cnt[x]++;
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++) pos[i] = pos[i-1]+cnt[i-1];
    vector<int> p_new(n);
    for(auto x: p){
        p_new[pos[c[x]]] = x;
        pos[c[x]]++;
    }
    p = p_new;
}

pair<vector<int>, vector<vector<int>>> computeSuffixArray(string s){
    s += char(32); // use space as sentinel
    int n = s.size();
    vector<int> pos(n), c(n);
    vector<vector<int>> all_class;

    vector<pair<char,int>> a(n);
    for(int i=0;i<n;i++) a[i]={s[i],i};
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) pos[i]=a[i].second;
    c[pos[0]]=0;
    for(int i=1;i<n;i++) c[pos[i]]=c[pos[i-1]] + (a[i].first != a[i-1].first);
    all_class.push_back(c);

    int k=0;
    while((1<<k)<n && c[pos[n-1]]<n-1){
        for(int i=0;i<n;i++) pos[i] = (pos[i] - (1<<k) + n)%n;
        countSort(pos,c);
        vector<int> c_new(n);
        c_new[pos[0]]=0;
        for(int i=1;i<n;i++){
            pair<int,int> prev={c[pos[i-1]],c[(pos[i-1]+(1<<k))%n]};
            pair<int,int> curr={c[pos[i]],c[(pos[i]+(1<<k))%n]};
            c_new[pos[i]] = c_new[pos[i-1]] + (prev!=curr);
        }
        c=c_new;
        k++;
        all_class.push_back(c);
    }
    return {pos, all_class};
}

void sortSubstrings(vpi &a, const vector<vector<int>> &all_class){
    sort(a.begin(), a.end(), [&](pi A, pi B){
        int l1=A.first-1, r1=A.second-1, len1=r1-l1+1;
        int l2=B.first-1, r2=B.second-1, len2=r2-l2+1;
        int minLen=min(len1,len2);

        int k=0;
        while((1<<k)<=minLen) k++;
        k--;
        if(k>=all_class.size()) k=all_class.size()-1;

        pair<int,int> c1={all_class[k][l1], all_class[k][l1+minLen-(1<<k)]};
        pair<int,int> c2={all_class[k][l2], all_class[k][l2+minLen-(1<<k)]};

        if(c1!=c2) return c1<c2;
        if(len1!=len2) return len1<len2;
        return A<B;
    });
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n; cin >> n;
    vpi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    auto result = computeSuffixArray(s);
    sortSubstrings(a,result.second);
    for(auto [l,r]: a) cout << l << " " << r << "\n";
}
