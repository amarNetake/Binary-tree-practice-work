/*
Given a preorder traversal array result. Convert it into a tree.You will also be given with the states as follows
CONDITIONS:-
	1. When you visit the node push the node into the stack with state 1.
	2. When you find status of top node's state in stack is 1 then push the 
	next array element as left child of that node with state 1 and make the state of the node 2.
	3. When the state of node at top of stack is 2 then push the next node from array as right 
	child and make the state of node as 3.
	4. When the state of node at top of stack is 3 then pop the top of stack
	5. To insert NULL or to represent NULL data use 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> vect(n);
		for(int i=0;i<n;i++)
		{
			int data;
			cin>>data;
			if(data==0)
			{
				vect[i]=NULL;
			}
			else
			{
				vect[i]=data;
			}
		}
		Node* root=new Node(vect[0]);
		pair<Node*,int> pa=make_pair(root,1);
		stack<pair<Node*,int>> st;
		st.push(pa);
		int idx=0; //To traverse through the preorder vector 'vect'.
		while(st.empty()!=true)
		{
			if(st.top().second==1)
			{
				idx++;
				Node* temp=st.top().first;
				if(vect[idx]!=0)  //Here 0 =>NULL
				{
				    Node* new_node=new Node(vect[idx]);
				    temp->left=new_node;
				    st.top().second++;
				    st.push(make_pair(new_node,1));
				}
				else if(vect[idx]==0)   //Here 0 =>NULL
				{
				    st.top().second++;
				}
			}
			else if(st.top().second==2)
			{
				idx++;
				Node * temp=st.top().first;
				if(vect[idx]!=0)       //Here 0 =>NULL
				{
				    Node* new_node=new Node(vect[idx]);
				    temp->right=new_node;
				    st.top().second++;
				    st.push(make_pair(new_node,1));
				}
				else if(vect[idx]==0)  //Here 0 =>NULL
				{
				    st.top().second++;
				}
			}
			else if(st.top().second==3)
			{
				st.pop();
			}
		}
		cout<<"Preorder: ";
		preorder(root);
		cout<<"\n\n";
		cout<<"Inorder: ";
		inorder(root);
		cout<<"\n\n";
		cout<<"Postorder: ";
		postorder(root);
	}
	return 0;
}