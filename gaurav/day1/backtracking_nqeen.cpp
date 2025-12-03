#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
// 1-queen
// 0-empty
// 9 x 9 board
int count=0;
vector<vector<int>>board(8, vector<int>(8, 0));
bool check(int row, int col){
      for(int r=0; r<row; r++) if(board[r][col]==1)
}
bool queen(int col){
      if(col == 8) {
            count++;
            return true;
      }

      for(int row=0; row<8; row++){
            board[row][col]=1;
            if(check(row, col)){
                  queen(col+1);
            }
            board[row][col]=0;//backtrack
      }
}
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