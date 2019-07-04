#include <iostream>
#include<math.h>
using namespace std;

class quadratic
{
private:
	int a;
	int b;
	int c;

public:


	quadratic()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	quadratic(int l, int m, int n)
	{
		a = l;
		b = m;
		c = n;
	}

	quadratic operator + (quadratic q)
	{
		quadratic P;
		P.a = a + q.a;
		P.b = b + q.b;
		P.c = c + q.c;
		return P;
	}


	void solution()
	{
		float s = sqrt((b*b)-4*a*c);
		float sol1 = (-b+s)/(2*a);
		float sol2 = (-b-s)/(2*a);
		cout<<sol1<<"  "<<sol2<<endl;
	}

	void value(int l)
	{
		int v = a*l*l +b*l +c;
		cout<<"Value is "<<v<<endl;
	}


	friend istream & operator >>(istream &i,quadratic &q)
		{
			i>>q.a;
			i>>q.b;
			i>>q.c;
			return i;
		}

	friend ostream & operator <<(ostream &out, quadratic q)
		{
			out<<q.a<<"x2 + "<<q.b<<"x +"<<q.c<<endl;
			return out;
		}
};
int main()
{
	int x;
	char o,r;
	quadratic Q1,Q2;
	cout<<"Enter First Quadratic Equation (a,b,c)";
			cin>>Q1;

cout<<"Enter Second Quadratic Equation (a,b,c)";
			cin>>Q2;
quadratic Q3,Q4;
do
{
	cout<<"Enter Operation(Add = '+' or solution = 's' or value = 'v')"<<endl;
	cin>>o;
if(o=='+')
{
	Q3 = Q1+Q2;
	cout<<"Addition is "<<Q3<<endl;

}
else if(o=='s')
{
	cout<<"Solution of First Equation is  "<<endl;
	Q1.solution();

	cout<<"Solution of Second Equation is  "<<endl;
	Q2.solution();

}

else if(o=='v')
{
	cout<<"Enter value of x to find value "<<endl;
	cin>>x;
	cout<<"Value of first Equation is "<<endl;
	Q1.value(x);
	cout<<"Value of Second Equation is "<<endl;
	Q2.value(x);
}

cout<<"Do you want to continue(y/n)"<<endl;
		cin>>r;
}

while(r=='y');
	cout<<"Thank You"<<endl;
}

