#include <iostream>
using namespace std;

class complex
{
private:
	int real;
	int imag;

public:

	complex()
	{
		real = 0;
		imag = 0;
	}
	complex(int a, int b)
	{
		real =a;
		imag = b;
	}

	complex operator + (complex c)
	{
		complex P;
		P.real = real + c.real;
		P.imag = imag + c.imag;
		return P;
	}

	complex operator - (complex c)
		{
			complex P;
			P.real = real - c.real;
			P.imag = imag - c.imag;
			return P;
		}

	complex operator * (complex c)
		{
			complex P;
			P.real = c.real*real-c.imag*imag;
			P.imag = c.real*imag+c.imag*real;
			return P;
		}


	friend istream & operator >>(istream &i, complex &c)
	{
		i>>c.real;
		i>>c.imag;
		return i;
	}

	friend ostream & operator <<(ostream &o, complex c)
	{
		o<<c.real;
		if(c.imag<0)
		o<<c.imag<<"i"<<endl;
		else
			o<<"+"<<c.imag<<"i"<<endl;
		return o;
	}
};

int main()
{

	char o,r;
	complex C1,C2;
	cout<<"Enter First No.";
			cin>>C1;
cout<<"Enter Second No.";
			cin>>C2;
complex C3,C4,C5,C6;
do
{
	cout<<"Enter Operation(+ or - or * )"<<endl;
	cin>>o;
if(o=='+')
{
	C3 = C1+C2;
	cout<<"Addition is "<<C3<<endl;
}
else if(o=='*')
{
	C4 = C1*C2;
	cout<<"Multiplition is "<<C4<<endl;

}
else if(o=='-')
{
	C5 = C1-C2;
	cout<<"Subtraction is"<<C5<<endl;
}
cout<<"Do you want to continue(y/n)";
		cin>>r;
}

while(r=='y');
	cout<<"Thank You"<<endl;
}
