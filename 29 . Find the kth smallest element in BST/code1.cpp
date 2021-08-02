//Using O(n) time and O(n) space 

void findKthSmallest(Node* root,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    findKthSmallest(root->left,vect);
    vect.push_back(root->data);
    findKthSmallest(root->right,vect);
}

int KthSmallestElement(Node *root, int k)
{
    //add code here.
    vector<int> vect;
    findKthSmallest(root,vect);
    if(k>vect.size())
    {
        return -1;
    }
    return vect[k-1];
}