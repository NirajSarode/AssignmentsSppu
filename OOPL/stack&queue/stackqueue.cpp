#include <iostream>
#include <string.h>
#include <stack>
#include<queue>
using namespace std;

class stl
{
public:
	void insertst(stack <int> st)
	{
	    stack <int> s = st;
	    if(st.empty())
	    {
	    	cout<<"Stack is empty!"<<endl;
	    }
	    while (!s.empty())
	    {
	        cout << '\t' << s.top();
	        s.pop();
	    }
	    cout << '\n';

	}

	void insertq(queue <int> q)
		{

		if(q.empty())
		{
			cout<<"Queue is empty!"<<endl;
		}
			while(!q.empty())
			{
				cout<<q.front()<<"\t";
				q.pop();
			}
			cout<<endl;

		}


};

int main()
{
	stack <int> stck;
	queue <int> que;
	stl s;
	int n,e;
		do
		{
			cout<<"Enter"<<endl;
			cout<<"1 : Insert element"<<endl;
			cout<<"2 : Delete element"<<endl;
			cout<<"3 : Size of Stack and Queue"<<endl;
			cout<<"4 : Display Stack TOP and Queue FRONT"<<endl;
			cout<<"5 : Display Stack and Queue"<<endl;
			cout<<"0 : Exit"<<endl;
			cin>>n;
			switch(n)
			{
			case 1:
				cout<<"Enter element"<<endl;
				cin>>e;
				stck.push(e);
				cout<<"Element in Stack added."<<endl;
				que.push(e);
				cout<<"Element in Queue added."<<endl;
				break;
			case 2:
				e=stck.top();
				stck.pop();
				cout<<"Element from Stack deleted."<<endl;
				e=que.front();
				que.pop();
				cout<<"Element from Queue deleted."<<endl;
				break;
			case 3:
				cout<<"Size of Stack is ";
				cout<<stck.size()<<endl;
				cout<<"Size of Queue is ";
				cout<<que.size()<<endl;
				break;
			case 4:
				cout<<"Top of Stack is ";
				cout<<stck.top()<<endl;
				cout<<"Front of Queue is ";
				cout<<que.front()<<endl;
				break;
			case 5:
				cout<<"Stack is :-"<<endl;
				s.insertst(stck);
				cout<<"Queue is :-"<<endl;
				s.insertq(que);
				break;
			default:
				cout<<"Program Terminated!"<<endl;
			}

		}while(n!=0);
		return 0;

}
