//============================================================================
// Name        : calculator.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class calc
{
private:
	int a,b;

public:
	void add()
	{
		cout<<"Enter two numbers"<<endl;
		cin>>a>>b;
		cout<<a+b<<endl;
	}
	void sub()
	{
		cout<<"Enter two numbers"<<endl;
		cin>>a>>b;
		cout<<a-b<<endl;
	}
	void mul()
		{
			cout<<"Enter two numbers"<<endl;
			cin>>a>>b;
			cout<<a*b<<endl;
		}
	void div()
		{
			cout<<"Enter two numbers"<<endl;
			cin>>a>>b;
			cout<<a/b<<endl;
		}
};
int main() {
	calc c1;
	int x;
	cout<<"Enter operation"<<endl;
	cout<<"1 for Addition"<<endl;
	cout<<"2 for subtraction"<<endl;
	cout<<"3 for multiplication"<<endl;
	cout<<"4 for Division"<<endl;
	cin>>x;

	switch(x)
	{
	case 1 : c1.add();
		break;
	case 2 : c1.sub();
		break;
	case 3 : c1.mul();
		break;
	case 4 : c1.div();
		break;

	}

	return 0;
}
