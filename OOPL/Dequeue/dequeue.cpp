#include <iostream>
#include <string.h>
#include<deque>
using namespace std;

class deq
{
public:
	void showdq(deque <int> g)
	{
	    deque <int> :: iterator it;
	    for (it = g.begin(); it != g.end(); ++it)
	        cout << '\t' << *it;
	    cout << '\n';
	}
};

int main()
{
	deque <int> dque;
	deq d;
	int n,e;
		do
		{
			cout<<"Enter"<<endl;
			cout<<"1 : Insert element from Front"<<endl;
			cout<<"2 : Insert element from Back"<<endl;
			cout<<"3 : Size of DeQue"<<endl;
			cout<<"4 : Element at Front and Back"<<endl;
			cout<<"5 : Pop element from Front"<<endl;
			cout<<"6 : Pop element from Back"<<endl;
			cout<<"7 : Display  Deque"<<endl;
			cout<<"0 : Exit"<<endl;
			cin>>n;
			switch(n)
			{
			case 1:
				cout<<"Enter element"<<endl;
				cin>>e;
				dque.push_front(e);
				cout<<"Element in DeQue added from Front."<<endl;
				d.showdq(dque);
				break;
			case 2:
				cout<<"Enter element"<<endl;
				cin>>e;
				dque.push_back(e);
				cout<<"Element in DeQue added from Back."<<endl;
				d.showdq(dque);
				break;
			case 3:
				cout<<"Size of Deque is ";
				cout<<dque.size()<<endl;
				//cout<<"Max size of Deque is ";
				//cout<<dque.max_size()<<endl;
				d.showdq(dque);
				break;
			case 4:
				cout<<"Front Of Deque is ";
				cout<<dque.front()<<endl;
				cout<<"Back of Deque is ";
				cout<<dque.back()<<endl;
				d.showdq(dque);
				break;
			case 5:
				cout<<" Pop  Front Of Deque is "<<endl;
				dque.pop_front();
				d.showdq(dque);
				cout<<"Pop Back of Deque is "<<endl;
				dque.pop_back();
				d.showdq(dque);
				break;
			case 6:
				cout<<"Front Of Deque is ";
				cout<<dque.front()<<endl;
				cout<<"Back of Deque is ";
				cout<<dque.back()<<endl;
				d.showdq(dque);
				break;

			case 7:
				cout<<"Deque is :-"<<endl;
				d.showdq(dque);
				break;
			default:
				cout<<"Program Terminated!"<<endl;
			}

		}while(n!=0);
		return 0;

}
