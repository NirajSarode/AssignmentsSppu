#include <iostream>
#include <string.h>
using namespace std;

class personal
{
	string name,address;
	struct dob
	{
		int date;
		int month;
		int year;
	}D;
	int ph;
public:

	personal()
	{
		name="abc";
		address="abc";
		D.date=0;
		D.month=0;
		D.year=0;
		ph=0;
	}


	personal(string n,string a,int d,int m,int y,int p)
	{
		name=n;
		address=a;
		D.date=d;
		D.month=m;
		D.year=y;
		ph=p;
	}

	~personal()
	{
		cout<<"Personal destroyed"<<endl;
	}
	void getData()
	{
		cout<<"PERSONAL DETAILS"<<endl;
		cout<<"Enter name"<<endl;
		cin>>name;
		cout<<"Enter address"<<endl;
		cin>>address;
		cout<<"Enter DOB(DD/MM/YYYY)"<<endl;
		cin>>D.date>>D.month>>D.year;
		cout<<"Enter Phone No."<<endl;
		cin>>ph;

	}

	void putData()
	{
		cout<<"PERSONAL DETAILS"<<endl<<endl;
		cout<<"NAME - "<<name<<endl;
		cout<<"ADDRESS - "<<address<<endl;
		cout<<"DATE OF BIRTH(DD/MM/YYYY)"<<D.date<<"/"<<D.month<<"/"<<D.year<<endl;
		cout<<"PHONE NO. - "<<ph<<endl<<endl;
	}

};


class professional
{
	string comp_name,designation;
	int id;
public:

	professional()
	{
		comp_name="abc";
		designation="abc";
		id=0;
	}


	professional(string c,string d,int i)
	{
		comp_name=c;
		designation=d;
		id=0;
	}

	void getData()
	{
		cout<<"PROFESSIONAL DETAILS"<<endl;
		cout<<"Enter Company name"<<endl;
		cin>>comp_name;
		cout<<"Enter Designation"<<endl;
		cin>>designation;
		cout<<"Enter ID number"<<endl;
		cin>>id;

	}

	void putData()
	{
		cout<<"PROFESSIONAL DETAILS"<<endl<<endl;
		cout<<"COMPANY NAME - "<<comp_name<<endl;
		cout<<"DESIGNATION - "<<designation<<endl;
		cout<<"ID NO. - "<<id<<endl<<endl;
	}

};



class academics
{
	string qualification;
	int sscp,hscp;
public:

	academics()
	{
		qualification="abc";
		sscp=0;
		hscp=0;
	}


	academics(string q,int s, int h)
	{
		qualification = q;
		sscp=0;
		hscp=0;
	}

	void getData()
	{
		cout<<"ACADEMIC DETAILS"<<endl;
		cout<<"Enter SSC percentage"<<endl;
		cin>>sscp;
		cout<<"Enter HSC percentage"<<endl;
		cin>>hscp;
		cout<<"Enter Qualification"<<endl;
		cin>>qualification;

	}

	void putData()
	{
		cout<<"ACADEMIC DETAILS"<<endl<<endl;
		cout<<"SSC PERCENTAGE - "<<sscp<<"%"<<endl;
		cout<<"HSC PERCENTAGE - "<<hscp<<"%"<<endl;
		cout<<"QUALIFICATION - "<<qualification<<endl<<endl;
	}

};
class biodata : public personal, public professional, public academics
{
	string resumeTitle;
public:
	biodata()
	{
		resumeTitle="abc";
	}

	void getData()
	{
		cout<<"Enter Resume Title"<<endl;
		cin>>resumeTitle;
		personal::getData();
		professional::getData();
		academics::getData();
	}
	void putData()
	{
		cout<<"-------------"<<resumeTitle<<"-------------"<<endl;
		personal::putData();
		professional::putData();
		academics::putData();
	}
};

int main()
{
	int total,i;
	cout<<"Enter Total No. of employees"<<endl;
	cin>>total;
	biodata B[100];
	for(i=0;i<total;i++)
	{
		B[i].getData();
	}
	for(i=0;i<total;i++)
	{
		B[i].putData();
	}
}
