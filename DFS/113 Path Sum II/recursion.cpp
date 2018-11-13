#include <iostream>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findpath(root, sum, paths, path);
        return paths;
    }
    void findpath(TreeNode* root, int sum, vector<vector<int> > &paths, vector<int> &path){
        if(!root)
            return;
        path.push_back(root->val);
        if(root->val == sum && !root->left && !root->right)
            paths.push_back(path);
        findpath(root->left, sum - root->val, paths, path);
        findpath(root->right, sum - root->val, paths, path);
        path.pop_back();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
