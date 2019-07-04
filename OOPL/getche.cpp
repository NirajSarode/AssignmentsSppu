//============================================================================
// Name        : getche.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int main()
{
    int lines,i;
    int count;
	int x=0;
cout<<"Enter no. of lines\n";
cin>>lines;
count=(lines/2)-1;
for(i=0;i<lines;i++)
	{

        for(i=0;i<count;i++)
        {
            cout<<" ";
        }
        for(i=0;i<2*x+1;i++)
        {
            cout<<"X";
        }

        count--;
        x++;

        cout<<endl;
	}


	return 0;
}
