/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > retVal;

	    levelOrder(root, retVal, 0);

	    reverse(retVal.begin(), retVal.end());

	    return retVal;
    }
    void levelOrder(TreeNode* root, vector<vector<int> > &v, int currLevel) {
	if (root == NULL) {
		return;
	}

	if (v.empty() || currLevel > (v.size() - 1)) {
		v.push_back(vector<int>());
	}

	v[currLevel].push_back(root->val);

	levelOrder(root->left, v, currLevel + 1);
	levelOrder(root->right, v, currLevel + 1);
}
};

auto x=[]{
    std::ios_base::sync_with_stdio( false);
    std::cin.tie(nullptr);
    return 0;
}();
