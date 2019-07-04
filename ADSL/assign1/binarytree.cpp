#include<iostream>
using namespace std;
#include<stack>
#include<queue>
#include<utility>

class node
{
	node *right;
	node *left;
	int info;
public:
	node(){
		right=NULL;
		left=NULL;
		info=0;
}
	friend class btree;
};

class btree{
	node *root;
	queue<node*> f;
	public:
	btree(){
		root=NULL;
	}
	void create();
	node* createR();
	void inordernonrec();
	void postordernonrec();
	void preordernonrec();
	void inorderrec();
	void inorder(node*);
	void postorderrec();
	void postorder(node*);
	void preorderrec();
	void preorder(node*);
	int height();
	int heightR(node*);
	void leafinteriornode();
	void delnode();
	void del(node*);
	node* mirror(node*);
	node* getroot();
	void setroot(node*);
	void operator=(btree&);
	node* copy(node*);
};

void btree::create(){
	stack<node*> s;
	if(root==NULL){
		cout<<"Enter data for root:";
		int temp;
		cin>>temp;
		node* new1;
		new1=new node;
		new1->info=temp;
		root=new1;
		s.push(new1);
	}
	while(!s.empty()){
		node* temp=s.top();
		s.pop();
		cout<<"consider element "<<temp->info<<endl;
		cout<<"Does this have left child:(y/n)";
		char op;
		int t;
		cin>>op;
		if(op=='y'){
			cout<<"enter data for left:(y/n)";
			cin>>t;
			node* new1=new node;
			new1->info=t;
			temp->left=new1;
			s.push(new1);
		}
		cout<<"Does this have right child:(y/n)";
		cin>>op;
		if(op=='y'){
			cout<<"Enter data for right:";
			cin>>t;
			node* new1=new node;
			new1->info=t;
			temp->right=new1;
			s.push(new1);
		}
	}
}
	
node* btree::createR(){
	int val,ch;
	cout<<"Enter value of node: ";
	cin>>val;
	if(val==-1)
		return NULL;
	else{
		node *p=new node;
	    p->info=val;
	   cout<<"Does "<<p->info<<"left child?(1-y)";
	   cin>>ch;
	   if(ch==1)
		   p->left=createR();
	   cout<<"Does "<<p->info<<"right child?(1-y)";
	   cin>>ch;
	   if(ch==1)
	   	   p->right=createR();
	   return p;
	}
}

	void btree::inorder(node *a){
		if(a!=NULL){
			inorder(a->left);
			cout<<a->info<<"\t";
			inorder(a->right);
		}
	}

	void btree::inordernonrec(){
		stack <node*> s;
		node *ptr=root;
		while(1){	
		while(ptr!=NULL){
			s.push(ptr);
			ptr=ptr->left;
		}
		if(s.empty())
			return;
		ptr=s.top();
		s.pop();
		cout<<ptr->info<<"\t";
		ptr=ptr->right;
		}
	}

	void btree::postorder(node *a){
		if(a!=NULL){
			postorder(a->left);
			postorder(a->right);
			cout<<a->info<<"\t";
		}
	}

	void btree::postordernonrec(){
	    stack <node*> s1,s2;
	    s1.push(root);
	    while(!s1.empty()){
		    node* temp;
		    temp=s1.top();
		    s1.pop();
		    s2.push(temp);

		    if(temp->left!=NULL){
			    s1.push(temp->left);
		    }
		    if(temp->right!=NULL)
			    s1.push(temp->right);
	    }
	    while(!s2.empty()){
		    node* temp=s2.top();
		    cout<<temp->info<<"\t";
		    s2.pop();
	    }
	}

	void btree::preorder(node *a){
		if(a!=NULL){
			cout<<a->info<<"\t";
			preorder(a->left);
			preorder(a->right);	
		}
	}

	void btree::preordernonrec(){
		stack<node*> s;
		node* ptr;
		ptr=root;

	    while(1){
		    while(ptr!=NULL){
			    cout<<ptr->info;
			    s.push(ptr);
			    ptr=ptr->left;
		    }
		    if(s.empty())
			    return;
		    ptr=s.top();
		    s.pop();
		    ptr=ptr->right;
	    }
	}
		
int btree::heightR(node *t){
	if(t==NULL)
		return -1;
	return(max(heightR(t->left),heightR(t->right))+1);
}

	int btree::height(){
		queue<node*> r;
		if(root==NULL){
			return 0;
		}	
		else{
			r.push(root);
			int h=0;
			while(1){
				int nc=r.size();
				if(nc==0){
					return h;
				}
				else{
					h++;
					while(nc>0){
						node *temp=r.front();
						r.pop();
						if(temp->left!=NULL)
							r.push(temp->left);
						if(temp->right!=NULL)
							r.push(temp->right);
						nc--;
					}
				}
			}
		}
	}

	void btree::leafinteriornode(){
	int l=0,in=0;
	stack<node*> s;
	node *temp;
	s.push(root);
	while(!s.empty()){
		temp=s.top();
		s.pop();
		if(temp->left==NULL && temp->right==NULL){
			l++;
		}
		else{
			in++;
		}
		if(temp->right!=NULL)
			s.push(temp->right);
		if(temp->left!=NULL)
			s.push(temp->left);
	}
	cout<<"Total leaf nodes:"<<l<<"\n"<<"Total internal nodes:"<<in;
}
	
	void btree::del(node *ptr){
		if(ptr!=NULL){
			del(ptr->left);
			del(ptr->right);
			delete ptr;
		}
	}

	node* btree::getroot(){
		return root;
	}

    node* btree::mirror(node *rt){
	    node* m_root=NULL;
	    if(rt==NULL){
		    return NULL;
	    }
	    m_root=new node;
	    m_root->info=rt->info;
	    m_root->left=mirror(rt->right);
	    m_root->right=mirror(rt->left);
	    return m_root;
    }

void btree::setroot(node *r){
	root=r;
}

void btree::operator=(btree &b){
	node *s=NULL;
	s=copy(b.root);
	setroot(s);
	cout<<"Inorder traversal of tree:"<<endl;
	inordernonrec();
	cout<<"\n";

	cout<<"Preorder traversal of tree:"<<endl;
	preordernonrec();
	cout<<"\n";

	cout<<"Postorder traversal of tree:"<<endl;
    postordernonrec();
    cout<<"\n";
}

node* btree::copy(node *rt){
	node* m_root=NULL;
	if(rt==NULL){
		return NULL;
	}
	m_root=new node;
	m_root->info=rt->info;
	m_root->left=mirror(rt->left);
	m_root->right=mirror(rt->right);

	return m_root;
}

int main(){
	btree a,b2,b3;
	int op,num;
	char op1;
	b:
	cout<<"enter the operation you want to perform"<<"\n";
	cout<<"1.create\n2.inorder\n3.postorder\n4.preorder\n5.height\n";
	cout<<"6.interior leaf nodes print\n7.delete node\n8.mirroring\n9.copying";
	cin>>op;
	switch(op){
		case 1:cout<<"1.recursively\n2.non-recursively\n";
			cin>>num;
			switch(num){
				case 1:node *r;
					r=a.createR();
					a.setroot(r);
					break;
				case 2:a.create();
					break;
			}
			break;
		case 2:cout<<"1.recursively\n2.non-recursively\n";
			cin>>num;
			switch(num){
			case 1:a.inorder(a.getroot());
				break;
			case 2:a.inordernonrec();
				break;
			}
			break;
		case 3:cout<<"1.recursively\n2.non-recursively\n";
			cin>>num;
			switch(num){
			case 1:a.postorder(a.getroot());
				break;
			case 2:a.postordernonrec();
				break;
			}
			break;
		case 4:cout<<"1.recursively\n2.non-recursively\n";
			cin>>num;
			switch(num){
			case 1:a.preorder(a.getroot());
				break;
			case 2:a.preordernonrec();
				break;
			}
			break;
		case 5:cout<<"1.recursively\n2.non-recursively\n";
			cin>>num;
			int h;
			switch(num){
			case 1:h=a.heightR(a.getroot());
				break;
			case 2:h=a.height();
				break;
			}
			cout<<"the height is:"<<h<<"\n";
			break;
		case 6:a.leafinteriornode();
			break;
		case 7:a.del(a.getroot());
			break;
		case 8:	cout<<"Mirror tree\n";
				node *mr;
				mr=a.mirror(a.getroot());
				b2.setroot(mr);

				cout<<"Inorder traversal of tree:"<<endl;
				b2.inordernonrec();
				cout<<"\n";

 			    cout<<"Preorder traversal of tree:"<<endl;
				b2.preordernonrec();
				cout<<"\n";

	      		cout<<"Postorder traversal of tree:"<<endl;
			    b2.postordernonrec();
			    cout<<"\n";
				break;
		case 9:cout<<"Copy tree\n";
				b3=a;
				break;
	}
	cout<<"do you want to do more operations";
	cin>>op1;
	if(op1=='y'||op1=='Y'){
		goto b;
	}
	return 0;
}
