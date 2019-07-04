#include <iostream>
#include <string.h>
#include<fstream>
using namespace std;


class student
{
	string name,address;
	int rollno,contact;
public:
	void getData(){
		cout<<"Enter name"<<endl;
		cin>>name;
		cout<<"Enter Rollno"<<endl;
		cin>>rollno;
		cout<<"Enter Address"<<endl;
		cin>>address;
		cout<<"Enter Contact"<<endl;
		cin>>contact;
	}


};

int main()
{

	student S;

	ofstream out("stud.txt",ios::binary);
	S.getData();
	out.write((char*)&S,sizeof(S));
	ifstream in("stud.txt",ios::binary);
	//out.write((char*)&S,sizeof(S));
	in.read((char*)&S,sizeof(S));

}
