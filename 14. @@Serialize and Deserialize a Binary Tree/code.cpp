/*
 NOTE:-
 string insert() function is used to insert single character.
 string append() function can append both character as well as string in the end of given string.
 append() function is much much faster than '+' operator to concatenate the strings.
*/

class Codec {
public:

    void preorder(TreeNode* root,string& result)
    {
        if(root==NULL) 
        {
            result.append("N#"); //append() function is much faster than regular string addition for concatenation
            return;
        }
        string value=to_string(root->val)+ "#";
        result.append(value);
        preorder(root->left,result);
        preorder(root->right,result);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        preorder(root,result);
        return result;
    }
    
    void extract(string& data,vector<string>& vect)
    {
        string temp="";
        for(auto x: data)
        {
            if(x=='#')
            {
                vect.push_back(temp);
                temp.clear();
            }
            else
            {
                temp.insert(temp.end(),x);
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vect;
        extract(data,vect);
        if(vect[0]=="N") return NULL;
        TreeNode* root=new TreeNode(stoi(vect[0]));
        pair<TreeNode*,int> pa=make_pair(root,1);
        stack<pair<TreeNode*,int>> s;
        s.push(pa);
        int i=0;
        while(s.empty()==false)
        {
            i++;
            pair<TreeNode*,int> curr=s.top();
            if(curr.second==1)
            {
                if(vect[i]!="N")
                {
                    TreeNode* new_node=new TreeNode(stoi(vect[i]));
                    s.top().first->left=new_node;
                    s.top().second++;
                    s.push(make_pair(new_node,1));
                }
                else
                {
                    s.top().second++;
                }
            }
            else if(curr.second==2)
            {
                if(vect[i]!="N")
                {
                    TreeNode* new_node=new TreeNode(stoi(vect[i]));
                    s.top().first->right=new_node;
                    s.top().second++;
                    s.push(make_pair(new_node,1));
                }
                else
                {
                    s.top().second++;
                }
            }
            else
            {
                i--;
                s.pop();
            }
        }
        return root;
    }
};