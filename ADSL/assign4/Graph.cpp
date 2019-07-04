//============================================================================
// Name        : Assign4.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class node
{
	string data;
	int weight;
	node* next;
public:
	node(string a,int x)
{
		data=a;
		weight=x;
		next=NULL;
}
	friend class graph;
};
class graph
{
	int n;
	string city[20];
	node* head[20];
public:
	graph()
{
		cout<<"Enter the number of cities to be represented on your network"<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			city[i]=" ";
			head[i]=NULL;
		}
}
	void create_list()
	{
		int x,cost;
		cout<<"Enter the city names: "<<endl;
		cin.ignore(1);
		for(int i=0;i<n;i++)
		{
			getline(cin,city[i]);
		}
		cout<<"The cities entered are: "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<". "<<city[i]<<endl;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"Is there a direct flight between "<<city[i]<<" and "<<city[j]<<"(1 for yes /0 for no)?: ";
				cin>>x;
				if(x==1)
				{
					cout<<"Enter the duration of flight: "<<endl;
					cin>>cost;
					if(head[i]==NULL)
					{
						head[i]=new node(city[j],cost);
					}
					else
					{
						node* temp=head[i];
						while(temp->next!=NULL)
						{
							temp=temp->next;
						}
						temp->next=new node(city[j],cost);
					}
				}
			}
		}
	}
	//ADDING A VERTEX AND EDGE
	void add_city()
	{
		int x,cost;
		string city1;
		cout<<"Enter the city to add"<<endl;
		cin>>city1;
		city[n]=city1;
		n=n+1;
		head[n-1]=NULL;
		cout<<"The cities in network are: ";
		for(int i=0;i<n;i++)
		{
			cout<<city[i]<<" ";
		}
		for(int i=0;i<n-1;i++)
		{
			cout<<"Is there a direct flight between "<<city[i]<<" and "<<city1<<"(1 for yes/0 for no)?";
			cin>>x;
			if(x==1)
			{
				cout<<"Enter the duration of flight"<<endl;
				cin>>cost;
				if(head[i]==NULL)
				{
					head[i]=new node(city1,cost);
				}
				else
				{
					node* temp=head[i];
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=new node(city1,cost);
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			cout<<"Is there a direct flight between "<<city1<<" and "<<city[i]<<"(1 for yes/0 for no)?";
			cin>>x;
			if(x==1)
			{
				cout<<"Enter the duration of flight"<<endl;
				cin>>cost;
				if(head[n-1]==NULL)
				{
					head[n-1]=new node(city[i],cost);
				}
				else
				{
					node* temp=head[n-1];
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=new node(city[i],cost);
				}
			}
		}

	}

	/*void delete_edge()
	{
		string city1;
		cout<<"Enter the city whose flights you want to delete"<<endl;
		cin>>city1;
		node*p,*temp;
		for(int i=0;i<n;i++)
		{
			p=head[i];
			temp=head[i]->next;
			while(temp!=NULL)
			{
				if(p->data==city1)
				{
					head[i]=temp;
					delete p;
				}
				if(temp->data==city1)
				{
					p->next=temp->next;
					delete temp;
				}
				p=p->next;
				temp=temp->next;
			}
		}
	}*/
	void delete_flight()
	{
		string city1,city2;
		cout<<"Enter the city to be changed"<<endl;
		cin>>city1;
		cout<<"Enter the flight to be deleted"<<endl;
		cin>>city2;
		int cnt=0;
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(city1==city[i])
			{
				k=i;
				cnt++;
			}
		}
		if(cnt==0)
		{
			cout<<"City to be changed not present"<<endl;
		}
		node* p=head[k];
		node* temp=head[k]->next;
		int cnt2=0;
		while(temp!=NULL)
		{
			if(p->data==city2)
			{
				head[k]=temp;
				delete p;
				cnt++;
			}
			if(temp->data==city2)
			{
				p->next=temp->next;
				delete temp;
				cnt2++;
			}
			p=p->next;
			temp=temp->next;
		}
		if(cnt2==0)
		{
			cout<<"Flight to be deleted not present"<<endl;
		}
	}

	void del_city()
	{
		string city1;
		int cnt=0,k=0;
		cout<<"Enter the city you want to delete from network"<<endl;
		cin>>city1;
		int i=0;
		while(i<n)
		{
			if(city1==city[i])
			{
				k=i;
				//cout<<"Deleting the city "<<city1<<endl;
				cnt++;
				break;
			}
			i++;
		}
		cout<<endl;
		cout<<"Position of city is "<<k<<endl;
		if(cnt==0)
		{
			cout<<"City not present"<<endl;
			return;
		}
		//DELETING VERTEX
		if(k==n-1)
		{
			cout<<"Last city"<<endl;
			head[n-1]=NULL;
			n=n-1;
		}
		else if(k!=n-1)
		{
			cout<<"Not last city"<<endl;
			for(int i=k;i<n;i++)
			{
				head[i]=head[i+1];
			}
			for(int i=k;i<n;i++)
			{
				city[i]=city[i+1];
			}
			city[n-1]=" ";
			n=n-1;
		}
		cout<<"Cities in network now are ";
		for(int i=0;i<n;i++)
		{
			cout<<city[i]<<" ";
		}
		cout<<endl;
		//DELETING EDGE
		for(int i=0;i<n;i++)
		{
			node* p=head[i];
			node* temp=head[i]->next;
			while(temp!=NULL)
			{
				if(p->data==city1)
				{
					head[i]=temp;
					delete p;
				}
				if(temp->data==city1)
				{
					p->next=temp->next;
					delete temp;
				}
				p=p->next;
				temp=temp->next;
			}
		}


	}


	void show_list()
	{
		for(int i=0;i<n;i++)
		{
			cout<<city[i]<<"-> ";
			//if(head[i]==NULL)
			//{
			//	cout<<"NULL "<<endl;
			//}
			if(head[i]!=NULL)
			{
				node* temp=head[i];
				while(temp!=NULL)
				{
					cout<<temp->data<<","<<temp->weight<<"-> ";
					temp=temp->next;
				}
			}
			cout<<endl;
		}
	}
	void outdegree()
	{
		cout<<"hi"<<endl;
		node* p;
		int cnt,sum;
		for(int i=0;i<n;i++)
		{
			cnt=0;
			sum=0;
			p=head[i];
			//cout<<"Inside for"<<endl;
			cout<<"Number of flights taking off from "<<city[i]<<" are ";
			while(p!=NULL)
			{
				sum=sum+p->weight;
				p=p->next;
				cnt++;
			}
			cout<<cnt<<endl;
			cout<<"The outdegree of"<<city[i]<<" is: "<<sum<<endl;
		}
	}
	void indegree()
	{
		node *temp1;
		string p;
		for(int i=0;i<n;i++)
		{
			p=city[i];
			int cnt=0;
			int sum=0;
			for(int j=0;j<n;j++)
			{
				temp1=head[j];
				while(temp1!=NULL)
				{
					if(temp1->data==p)
					{
						sum=sum+temp1->weight;
						cnt++;
					}
					temp1=temp1->next;
				}
			}
			cout<<"Number of flights landing in "<<city[i]<<" are "<<cnt<<endl;
			cout<<"The indegree of "<<city[i]<<" is"<<sum<<endl;
		}
	}

};
int main()
{
	graph obj;
	int ch,q=1;

	do{
		cout<<"Enter your choice"<<endl;
		cout<<"------MENU--------"<<endl;
		cout<<"1.Enter the details of network"<<endl;
		cout<<"2.Add a city to network"<<endl;
		cout<<"3.Delete a city from network"<<endl;
		cout<<"4.Delete a flight for a given city"<<endl;
		cout<<"5.Get number of flight taking off from each city"<<endl;
		cout<<"6.Get number of flights landing in each city"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			obj.create_list();
			cout<<"The network is:";
			obj.show_list();
			cout<<endl;
			break;
		}
		case 2:
		{
			obj.add_city();
			cout<<"The appended network is: ";
			obj.show_list();
			cout<<endl;
			break;

		}
		case 3:
		{
			obj.del_city();
			cout<<"The appended network is: ";
			obj.show_list();
			cout<<endl;
			break;
		}
		case 4:
		{
			obj.delete_flight();
			cout<<"The appended network is: ";
			obj.show_list();
			break;
		}
		case 5:
		{
			obj.outdegree();
			break;
		}
		case 6:
		{
			obj.indegree();
			break;
		}
		}
		cout<<"Do you want to continue(1 for yes / 0 for no)?"<<endl;
		cin>>q;
	}while(q==1);
	return 0;
}
