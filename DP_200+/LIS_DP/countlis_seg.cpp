#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pp pop_back
#define umap unordered_map
#define uset unordered_set
#define lb(arr, x) (lower_bound(all(arr), (x)) - (arr).begin())
#define ub(arr, x) (upper_bound(all(arr), (x)) - (arr).begin())

vpi seg;
pi choosebest(const pi &a, const pi &b){
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return {a.first, a.second + b.second};
}
pi query(int left, int right, int qs, int qe, int parent){
    if (qs > right || qe < left) return {0, 0}; 
    if (qs <= left && right <= qe) return seg[parent]; 
    int mid = left + (right - left) / 2;
    pi l = query(left, mid, qs, qe, parent << 1);
    pi r = query(mid + 1, right, qs, qe, parent << 1 | 1);
    return choosebest(l, r);
}
void update(int left, int right, int parent, int element, int mxlen, int ways){
    if (left == right){
        if (seg[parent].first > mxlen) {
            // do nothing
        } else if (seg[parent].first == mxlen) {
            seg[parent].second += ways;
        } else {
            seg[parent] = {mxlen, ways};
        }
        return;
    }
    int mid = left + (right - left) / 2;
    if (element <= mid) update(left, mid, parent << 1, element, mxlen, ways);
    else update(mid + 1, right, parent << 1 | 1, element, mxlen, ways);
    seg[parent] = choosebest(seg[parent << 1], seg[parent << 1 | 1]);
}
int ranked(vi &arr){
    vi temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (auto &x : arr) {
        x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
    }
    return (int)temp.size();
}
void solve(){
    int n;
    if (!(cin >> n)) return;
    vi arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int elements = ranked(arr); 
    seg.assign(4 * elements + 5, {0, 0});   
    for (int i = 0; i < n; ++i){
        int mxlen = 1, ways = 1;
        if (arr[i] > 0) {
            pi info = query(0, elements - 1, 0, arr[i] - 1, 1); 
            if (info.first > 0) {
                mxlen = info.first + 1;
                ways = info.second;
            } else {
                mxlen = 1;
                ways = 1;
            }
        }
        update(0, elements - 1, 1, arr[i], mxlen, ways);
    }
    cout << seg[1].second << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
