#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
class person
{
public:
	string name,dob;
	long no;
	void get()
	{
		cout<<"Enter Name"<<endl;
		cin>>name;
		cout<<"Enter Date of Birth"<<endl;
		cin>>dob;
		cout<<"Enter Mobile Number"<<endl;
		cin>>no;
	}
	void put()
	{
		cout<<"Person Record"<<endl<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"Date of Birth : "<<dob<<endl;
		cout<<"Mobile Number : "<<no<<endl<<endl;
	}
};
int main()
{
	int n,i,j;
	string q;
	cout<<"Enter the number of records"<<endl;
	cin>>n;
	person p[n];
	string a[n];
	for(i=0;i<n;i++)
	{
		p[i].get();
		a[i]=p[i].name;
	}
	sort(a,a+n);
	cout<<"After sorting the records by name :-"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==p[j].name)
				p[j].put();
		}
	}
	cout<<"Enter Person Name to search the record"<<endl;
	cin>>q;
	if(binary_search(a,a+n,q))
	{
		cout<<"The required person record is found :-"<<endl;
		for(i=0;i<n;i++)
		{
			if(q==a[i])
				p[i].put();
		}
	}
	else
		cout<<"The required person record is NOT found!"<<endl;
}
