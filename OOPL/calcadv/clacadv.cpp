//============================================================================
// Name        : calculator.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================

#include <iostream>
using namespace std;


class calc
{
private:
	float a,b,l;

public:
	void add(float a,float b)
	{
		l=a+b;
	}
	void sub(float a,float b)
	{
		l=a-b;
	}
	void mul(float a,float b)
		{
			l=a*b;
		}
	void div(float a,float b)
		{
			l=a/b;
		}
};
int main() {
	calc c1;
	float w,x,y,z;
	float m,n;
	char a,b,c,d;
	do
	{
	cout<<"Enter Expression"<<endl;
	cin>>w>>a>>x>>b>>y>>c>>z;

	if(a=='/')
	{
		c1.div(w,x);

	}
		else if(b=='/')
		{
			c1.div(x,y);
		}
				else if(c=='/')
				{
					c1.div(y,z);
				}

	cout<<"Do you want to continue?(y/n)"<<endl;
			cin>>d;
	}
	while(d=='y');
	cout<<"Thank You"<<endl;
	return 0;
}
