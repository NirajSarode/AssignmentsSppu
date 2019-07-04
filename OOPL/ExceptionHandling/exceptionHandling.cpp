#include <iostream>
#include <string.h>
using namespace std;

class exceptn
{
	int age;
	double income;
	string city;
	bool veh;
public:
	exceptn(int age)
	{
		this->age=age;
		this->income=income;
		this->city=city;
		this->veh=veh;
	}
	exceptn(double income)
	{
		this->age=age;
		this->income=income;
		this->city=city;
		this->veh=veh;
	}
	exceptn(string city)
	{
		this->age=age;
		this->income=income;
		this->city=city;
		this->veh=veh;
	}
	exceptn(bool veh)
	{
		this->age=age;
		this->income=income;
		this->city=city;
		this->veh=veh;
	}
	void getAge()
	{
		cout<<"Invalid Age"<<endl;
	}
	void getIncome()
		{
			cout<<"Invalid Income"<<endl;
		}
	void getCity()
		{
			cout<<"Invalid City"<<endl;
		}
	void getVeh()
		{
			cout<<"Invalid Vehicle"<<endl;
		}
};

int main()
{
	int age;
	double income;
	string city;
	bool veh;

	try
	{
		cout<<"Enter age"<<endl;
		cin>>age;
		if(age<18 || age>55)
			throw exceptn(age);
		else
			cout<<age<<endl;

	}
	catch(exceptn e)
	{
		e.getAge();
	}


	try
	{
		cout<<"Enter Income"<<endl;
		cin>>income;
		if(income<50000 || income>100000)
			throw exceptn(income);
		else
			cout<<income<<endl;

	}
	catch(exceptn e)
	{
		e.getIncome();
	}

	try
	{
		cout<<"Enter city"<<endl;
		cin>>city;
		if(city=="Pune" || city=="Mumbai" || city=="Bangalore" || city=="Chennai")
			cout<<city<<endl;

		else
			throw exceptn(city);

	}
	catch(exceptn e)
	{
		e.getCity();
	}

	try
	{
		cout<<"Enter Vehicle Type(if 4 wheeler = 1 else 0)"<<endl;
		cin>>veh;
		if(veh==false)
			throw exceptn(veh);
		else if(veh==true)
			cout<<"4 Wheeler"<<endl;

	}
	catch(exceptn e)
	{
		e.getVeh();
	}

}
