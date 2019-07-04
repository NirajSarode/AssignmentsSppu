#include <iostream>
#include <string.h>
using namespace std;

class student
{
private:
	string name,blood_group,address;
	int roll_no,standard,division,dob,contact,driving_lic;
public:


		student()
		{
			roll_no=0;
			standard=0;
			division=0;
			dob=0;
			contact=0;
			driving_lic=0;
			name='abc';
			blood_group='abc';
			address='abc';
		}



		student(int r,int s,int d,int db,int c,int l,string n,string b,string a)
		{
			roll_no=r;
			standard=s;
			division=d;
			dob=db;
			contact=c;
			driving_lic=l;
			name=n;
			blood_group=b;
			address=a;
		}




		student(student& S)
		{
			name=S.name;
			roll_no=S.roll_no;
			standard=S.standard;
			division=S.division;
			dob=S.dob;
			contact=S.contact;
			blood_group=S.blood_group;
			address=S.address;
			driving_lic=S.driving_lic;
		}
		~student()
		{
			cout<<"Destructed"<<endl;
		}



		void getdata()
		{
			cout<<"Enter Name"<<endl;
			cin>>name;

			cout<<"Enter Roll No."<<endl;
			cin>>roll_no;

			cout<<"Enter Standard"<<endl;
			cin>>standard;

			cout<<"Enter Division"<<endl;
			cin>>division;

			cout<<"Enter DateOfBirth(DDMMYYY)"<<endl;
			cin>>dob;

			cout<<"Enter Contact No."<<endl;
			cin>>contact;

			cout<<"Enter Blood Group"<<endl;
			cin>>blood_group;

			cout<<"Enter Address"<<endl;
			cin>>address;

			cout<<"Enter Driving Licence No."<<endl;
			cin>>driving_lic;
		}

		void putdata()
				{
					cout<<"Name - ";
					cout<<name<<endl;

					cout<<"Roll No. - ";
					cout<<roll_no<<endl;

					cout<<"Standard - ";
					cout<<standard<<endl;

					cout<<"Division - ";
					cout<<division<<endl;

					cout<<"DateOfBirth(DDMMYYY) - ";
					cout<<dob<<endl;

					cout<<"Contact No. - ";
					cout<<contact<<endl;

					cout<<"Blood Group - ";
					cout<<blood_group<<endl;

					cout<<"Address - ";
					cout<<address<<endl;

					cout<<"Driving Licence No. - ";
					cout<<driving_lic<<endl;
				}




};

int main()
{
	int total,i;
	cout<<"Enter Total No. of sudents"<<endl;
	cin>>total;
	student S[100];
	for(i=0;i<total;i++)
	{
	student S2();
	}
	for(i=0;i<total;i++)
	{
	S[total].getdata();
	}

	for(i=0;i<total;i++)
	{
	S[total].putdata();
	}

}
