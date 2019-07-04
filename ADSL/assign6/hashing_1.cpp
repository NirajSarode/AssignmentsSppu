//============================================================================
// Name        : assign6.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;
const int MAX=10;


class hashtable
{
	int arr_key[MAX];
	int arr_val[MAX];
	int flag[MAX];

public:
	hashtable()
{
		for(int i=0;i<MAX;i++)
		{
			arr_key[i]=0;
			arr_val[i]=0;
			flag[i]=0;
		}
}

	void insertr(int,int);
	void insert(int,int);
	void search(int);
	void display();
	void deletekey(int key);


};

void hashtable::insert(int key,int value)
{
	int index;
	index= key % MAX;

	if(flag[index]==0)
	{
		arr_key[index]=key;
		arr_val[index]=value;
		flag[index]=1;
		return;
	}

	for(int i=index+1;i!=index;i=(i+1)%MAX)
	{
		if(flag[i]==0)
		{
			arr_key[i]=key;
			arr_val[i]=value;
			flag[i]=1;
			return;
		}
	}

	cout<<"No empty location !\n";
	return;
}

void hashtable::insertr(int key,int value)
{
	int index;
	index= key % MAX;

	if(flag[index]==0)
	{
		arr_key[index]=key;
		arr_val[index]=value;
		flag[index]=1;
		return;
	}
	else if(arr_key[index] % MAX != index)
	{
		int temp1,temp2;
		temp1=arr_key[index];
		temp2=arr_val[index];
		arr_key[index]=key;
		arr_val[index]=value;

		for(int i=index+1;i!=index;i=(i+1)%MAX)
		{
			if(flag[i]==0)
			{
				arr_key[i]=temp1;
				arr_val[i]=temp2;
				flag[i]=1;
				return;
			}
		}
		arr_key[index]=temp1;
		arr_val[index]=temp2;
		cout<<"Insertion unsuccessful.\n";
		return;
	}

	else{
		for(int i=index+1;i!=index;i=(i+1)%MAX)
		{
			if(flag[i]==0)
			{
				arr_key[i]=key;
				arr_val[i]=value;
				flag[i]=1;
				return;
			}
		}

		cout<<"No empty location !\n";
		return;
	}

}

void hashtable::search(int key)
{
	int index;
	index = key % MAX;

	for(int i=0;i<MAX;i++)
	{
		if(flag[index]==1 && arr_key[index]==key)
		{
			cout<<"\nKey found at "<<index<<" th loc with value "<<arr_val[index];
			return;
		}
		else
			index = (index+1) % MAX;
	}

	cout<<"Key not found !";
	return;
}

void hashtable::deletekey(int key)
{
	int index;
	index = key % MAX;

	for(int i=0;i<MAX;i++)
	{
		if(flag[index]==1 && arr_key[index]==key)
		{
			arr_key[index]=0;
			arr_val[index]=0;
			flag[index]=0;
			cout<<"Key deleted.\n";
			return;
		}
		else
			index = (index+1) % MAX;
	}

	cout<<"Key not found !";
	return;
}

void hashtable::display()
{
	for(int i=0;i<MAX;i++)
	{
		cout<<"\n Key at "<<i<<" th index is "<<arr_key[i]<<" with value "<<arr_val[i];
	}
}

int main() {

	int ch;
	char c;
	int key,val;
	hashtable T;

	do{
		cout<<"Enter your choice:\n"
				<<"1.Insert with replacement.\n"
				<<"2.Insert without replacement.\n"
				<<"3.Find.\n"
				<<"4.Display hash table.\n"
				<<"5.Delete.\n";
		cin>>ch;

		switch(ch)
		{
		case 1:
		{
			cout<<"Enter the key.\n";
			cin>>key;
			cout<<"Enter the value.\n";
			cin>>val;
			T.insertr(key,val);

			break;
		}

		case 2:
		{
			cout<<"Enter the key.\n";
			cin>>key;
			cout<<"Enter the value.\n";
			cin>>val;
			T.insert(key,val);
			break;
		}

		case 3:
		{
			cout<<"Enter the key.\n";
			cin>>key;
			T.search(key);
			break;
		}

		case 4:
		{
			cout<<"The hash table is as follows \n";
			T.display();
			break;
		}

		case 5:
		{
			cout<<"Enter the key.\n";
			cin>>key;
			T.deletekey(key);
			break;
		}

		default:
			cout<<"Wrong choice !";
		}

		cout<<"\n Continue ?";
		cin>>c;

	}while(c=='y'||c=='Y'||c=='1');
	return 0;
}
