// Using iterative level order traversal

vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> vect;
        q.push(root);
        int countNodes=0;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0)
            {
                break;
            }
            while(countNodes>0)
            {
                if(countNodes==1)  //If this is the last node in this level
                {
                    vect.push_back(q.front()->val);
                }
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                countNodes--;
            }
        }
        return vect;
    }