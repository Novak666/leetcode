class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        vector<TreeLinkNode*> tmp;
        queue<TreeLinkNode*> q;
        if(!root) return;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeLinkNode* node = q.front();
            q.pop();
            if(!node)
            {
                linker(tmp);
                tmp.clear();
                if(q.size() > 0){q.push(NULL); };
            }else{
                tmp.push_back(node);
                if(node -> left != NULL){
                    q.push(node -> left);
                    q.push(node -> right);
                }
            }
        }

    }

    void linker(vector<TreeLinkNode*>& nodes)
    {
        for(int i = 0; i < nodes.size() - 1; ++i)
            nodes[i] -> next = nodes[i + 1];
        nodes.back() -> next = NULL;
    }
};
