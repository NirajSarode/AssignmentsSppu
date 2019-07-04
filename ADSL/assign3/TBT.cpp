//============================================================================
// Name        : assign3.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
using namespace std;

void choices();

class node
{
	char data;
	node* lc;
	node* rc;
	int flag;
	int lbit,rbit;
public:
	node(char x)
	{
		data=x;
		lc=NULL;
		rc=NULL;
		lbit=rbit=1;
		flag=-1;
	}

	friend class tbt;
};


class tbt
{

public:
	node* head;

	tbt()
	{
		head=new node(0);
		head->lbit=1;
		head->rbit=1;
		head->rc=head;
		head->lc=head;

	}

	void create()
	{
		insert(head,0);
	}

	void insert(node*,int);



	void preorder(node*);
	node* preorder_succ(node*);


	void inorder(node*);
	node* inorder_succ(node*);



	/*void b_delete()
	{
		rec_delete(root);
		cout<<"All the nodes of Tree deleted."<<endl;
	}

	void rec_delete(node*);
*/

};

void tbt::insert(node* dad,int flag)
{

	cout<<"Enter the data or - for no node"<<endl;
	char x;
	cin>>x;
	node* t;
	if(x=='-')
	{
		return;
	}

	else
	{

		if(flag==0)
		{
			t=new node(x);
			t->lbit=1;
			t->rbit=1;
			dad->lbit=0;
			t->rc=dad;
			t->lc=dad->lc;
			dad->lc=t;
			t->flag=flag;

		}

		if(flag==1)
		{
			t=new node(x);
			t->rbit=1;
			t->lbit=1;
			dad->rbit=0;
			t->rc=dad->rc;
			t->lc=dad;
			dad->rc=t;
			t->flag=flag;

		}
	}

	cout<<"For left child of "<<x<<endl;
	insert(t,0);
	cout<<"For right child of "<<x<<endl;
	insert(t,1);
}

void tbt::preorder(node* T)
{

	do
	{
		T=T->lc;
		cout<<T->data<<"  ";

	}while(T->lbit==0);

	while(T!=head)
	{

		T=preorder_succ(T);
		if(T==head)
			break;
		cout<<T->data<<"  ";
	}
}

node* tbt::preorder_succ(node* t)
{
	if(t->lbit==0)
		return t->lc;
	else if(t->rbit==0)
		return t->rc;
	else{
		t=t->rc;
		if(t->rbit==0)
		{
			return t->rc;
		}

		while(t->rbit==1)
		{
			if(t==head)
				return t;
			t=t->rc;
		}
		return t->rc;

	}
}


void tbt::inorder(node* T)
{
	T=T->lc;
	while(T->lbit==0)
	{
		T=T->lc;
	}

	while(T!=head)
	{
		cout<<T->data<<"  ";
		T=inorder_succ(T);
	}
}

node* tbt::inorder_succ(node* t)
{
	if(t->rbit==1)
		return t->rc;
	else{
		t=t->rc;
		while(t->lbit==0)
		{
			t=t->lc;
		}
		return t;
	}
}



/*void tbt::rec_delete(node* T)
{
	if(T==NULL)
		return;

	rec_delete(T->lc);
	rec_delete(T->rc);
	delete T;

}*/



int main()
{
	int y=1;
	tbt t1;

	do
	{
		choices();
		int ch;
		cin>>ch;

		switch(ch)
		{
			case 1:
				t1.create();
				cout<<"Tree created"<<endl;
				break;

			case 2:
				t1.preorder(t1.head);
				break;

			case 3:
			t1.inorder(t1.head);
				break;

			case 4:

				break;

			case 5:

				break;



			default:
				cout<<"Invalid Choice !"<<endl;
		}

		cout<<"Do you want to continue ? (0/1)"<<endl;
		cin>>y;
	}while(y==1);

	return 0;
}



void choices()
{
	cout<<"1. Create threaded binary tree"<<endl;
	cout<<"2. Display preorder"<<endl;
	cout<<"3. Display inorder"<<endl;
	cout<<"4. To delete all nodes of tree"<<endl;
}
