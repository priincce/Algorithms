#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000000;  
    vector<int> a(N + 1, 1);
    a[0] = a[1] = 0;
    for (int i = 2; i * 1LL * i <= N; i++){
        if (a[i]) {
            for (int j = i * i; j <= N; j += i){
                a[j] = 0;
            }
        }
    }
    for(int i=1;i<=N;i++){
      a[i]+=a[i-1];
    }

    int t;
    cin >> t;
    while(t--){
      int n;

    }

    return 0;
}
