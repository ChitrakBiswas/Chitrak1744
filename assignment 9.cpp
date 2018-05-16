/*
Create a class tree to implement  
i) Pre-order traversal 
ii) In-order traversal 
iii) Post-order traversal 
Use appropriate constructor and destructor.
*/

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node *left,*right;
}node;

class Tree{
	node* root;
	public:
	 Tree(); // making the tree , constructor
	 node* maketree(); // making the tree 
	void PreOrder(); //PreOrder Traversal
	void PreOrder(node*);
	void InOrder(); //InOrder Traversal
	void InOrder(node*);
	void PostOrder(); //PostOrder Traversal
	void PostOrder(node*); 
};
Tree::Tree()
{
	root=maketree();
}

node* Tree::maketree()
{
	int d;
	node* q;
	cout<<"Enter data: "; cin>>d;
	if(d)
	{
		q=new node();
		q->data=d;
		cout<<"Enter The LeftChild of "<<d<<endl;
		q->left=maketree();
		cout<<"Enter The RightChild of "<<d<<endl;
		q->right=maketree();
		
		return q;	
	}
	else
	return NULL;
}

//Traversals
void Tree::PreOrder()
{
	PreOrder(this->root);
}
void Tree::PreOrder(node* ptr)
{
	if(ptr)
	{
		cout<<ptr->data<<" ";
		PreOrder(ptr->left);
		PreOrder(ptr->right);
	}
}

void Tree:: InOrder()
{
	InOrder(this->root);
}
void Tree:: InOrder(node* ptr)
{
	if(ptr)
	{
		InOrder(ptr->left);
		cout<<ptr->data<<" ";
		InOrder(ptr->right);
	}
}

void Tree:: PostOrder()
{
	PostOrder(this->root);
}
void Tree:: PostOrder(node* ptr)
{
	if(ptr)
	{
		PostOrder(ptr->left);
		PostOrder(ptr->right);
		cout<<ptr->data<<" ";
	}
}

//main begins
int main()
{
	cout<<"Enter 0 as data to indicate leaf nodes\n";
	Tree object;
	cout<<"\nPreOrder Traversal.\n";
	object.PreOrder();
	cout<<"\nInOrder Traversal.\n";
	object.InOrder();
	cout<<"\nPostOrder Traversal.\n";
	object.PostOrder();
	
	return 0;
}
