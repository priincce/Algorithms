#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class TreeNode{
      public:
      int val;
      TreeNode*left, *right;
      TreeNode(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
      }
}



TreeNode* trim_zero(TreeNode*&root){
      if(!root) return nullptr;
      
      root->left =trim_zero(root->left);
      root ->right =trim_zero(root->right);

      if(!root->left && !root->right && root->val==0){
            return nullptr;
      }

      return root;

}
int main() {
    

    return 0;
}
