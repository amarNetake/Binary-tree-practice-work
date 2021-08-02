// Here we do not have to search for the exact key but need to search the extreme predecessor and 
// successor of the given key as exact key may be present or may be not. We do not care about that here.

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL) return;
    if(pre==NULL || (pre->key <root->key && root->key<key))    pre=root->key<key?root:NULL;
    if(suc==NULL || (suc->key >root->key && root->key>key))    suc=root->key>key?root:NULL;
    findPreSuc(root->left,pre,suc,key);
    findPreSuc(root->right,pre,suc,key);
}