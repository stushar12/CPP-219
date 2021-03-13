#include<bits/stdc++.h>
using namespace std;


struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}


void level(Node* root, int height, int &ans)								//all leaf nodes are at same level
{
    if(root==NULL)
    return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        if(ans==-1)
        {
            ans=height;
        }
        else if(ans!=height)
        {
            ans=0;
            return;
        }
    }
    
    level(root->left,height+1,ans);
    level(root->right,height+1,ans);
}


bool check(Node *root)
{
 int ans=-1;
 int h=0;
 level(root,h,ans);
 
 return ans;
}


int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

    cout<<check(root);
}	