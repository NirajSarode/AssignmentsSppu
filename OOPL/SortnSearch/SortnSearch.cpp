#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#include<queue>
using namespace std;

class stl
{
	string a[100];
	int i,n;

public:
	void getData()
	{
		cout<<"Enter no. of People"<<endl;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cout<<"Enter Name"<<endl;
			cin>>a[i];
			/*cout<<"Enter DOB"<<endl;
			cin>>a[i+1];
			cout<<"Enter Ph.No"<<endl;
			cin>>a[i+2];*/
		}
	}

	void sortByName()
	{
		int N = sizeof(a)/sizeof(a[0]);

		sort(a,a+N);

		for(int i = 0; i < N; i++){
		    cout << a[i] << endl;
		}
	}

};
