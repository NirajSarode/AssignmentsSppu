#include <iostream>
using namespace std;


class calc
{
private:
	int a,b;

public:
	void add(int a,int b)
	{
		cout<<a+b<<endl;
	}
	void sub(int a,int b)
	{
		cout<<a-b<<endl;
	}
	void mul(int a,int b)
		{
			cout<<a*b<<endl;
		}
	void div(int a,int b)
		{
			cout<<a/b<<endl;
		}
};
int main() {
	calc c1;
	int x,y,z;
	char a;
	cout<<"Enter Expression"<<endl;
	cin>>x>>a>>y;

	do
	{
	switch(a)
	{
	case '+' : c1.add(x,y);
		break;
	case '-' : c1.sub(x,y);
		break;
	case '*' : c1.mul(x,y);
		break;
	case '/' : c1.div(x,y);
		break;

	}
	cout<<"Do you want to continue?(y/n)"<<endl;
			cin>>a;
	}
	while(a=='y');
	cout<<"Thank You"<<endl;
	return 0;
}
