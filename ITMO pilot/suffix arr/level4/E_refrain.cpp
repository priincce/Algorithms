#include <bits/stdc++.h>
using namespace std;


void countSort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c) cnt[x]++;
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];
    vector<int> p_new(n);
    for (auto x : p) {
        p_new[pos[c[x]]] = x;
        pos[c[x]]++;
    }
    p = p_new;
}

pair<vector<int>, vector<int>> computeSuffixArray(vector<int>& s) {
    s.push_back(0); 
    int n = s.size();
    vector<int> p(n), c(n);

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) a[i]={s[i],i};
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) p[i]=a[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;i++) c[p[i]]=c[p[i-1]] + (a[i].first!=a[i-1].first);

    int k=0;
    while((1<<k)<n && c[p[n-1]]<n-1) {
        for(int i=0;i<n;i++) p[i]=(p[i]-(1<<k)+n)%n;
        countSort(p,c);
        vector<int> c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++) {
            pair<int,int> prev={c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
            pair<int,int> curr={c[p[i]], c[(p[i]+(1<<k))%n]};
            c_new[p[i]]=c_new[p[i-1]] + (prev!=curr);
        }
        c=c_new;
        k++;
    }
    return {p,c};
}
vector<int> computeLCP(const vector<int> &p, const vector<int> &c, const vector<int>& s) {
    int n = p.size();
    vector<int> lcp(n-1);
    int k=0;
    for(int i=0;i<n-1;i++){
        int pi = c[i];
        // FIX 3: Check for rank 0 to prevent out-of-bounds access
        if (pi == 0) {
            k = 0;
            continue;
        }
        int j = p[pi-1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[pi-1]=k;
        k=max(k-1,0);
    }
    return lcp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m; 
    vector<int> s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    auto [p,c] = computeSuffixArray(s);
    vector<int> lcp = computeLCP(p,c,s);
    lcp.push_back(0);
    long long maxprod = 0; 
    int bestlen = 0, bestpos = 0;
    stack<pair<int,int>> st; 

    for(int i=0;i<lcp.size();i++){
        int start_pos = i;
        while(!st.empty() && st.top().first >= lcp[i]){
            auto [h,pos_idx] = st.top(); st.pop();
            long long count = i - pos_idx + 1; 
            long long product = (long long)h * count;
            if(product > maxprod){
                maxprod = product;
                bestlen = h;
                bestpos = p[pos_idx];
            }
            start_pos = pos_idx;
        }
        st.push({lcp[i], start_pos});
    }
    if(n > maxprod){
        maxprod = n;
        bestlen = n;
        bestpos = 0;
    }

    cout << maxprod << "\n";
    cout << bestlen << "\n";
    for(int i=0;i<bestlen;i++) cout << s[i + bestpos] << " ";
    cout << "\n";
}