
#include<iostream>

using namespace std;

class heap

{
	int max,n1 = 0,n2 = 0;;
	int *data1;
	int *data2;
	
	public:
	
	heap(int max)
		{
			this->max = max;
			data1 = new int[max + 1];
			data2 = new int[max + 1];
		}
	
	void min_heap(int);
	void max_heap(int);	
	void display();
};

void heap :: min_heap(int x)

{
	int i;
	if(n1 == max)
		cout<<"ENTRIES ARE FULL"<<endl;
		
	else
		{
			n1++;
			for(i = n1;i >= 1;)
				{
					if(i == 1)
						break;
					
					if(x >= data1[i/2])
						break;
					
					else
						{
							data1[i] = data1[i/2];
							i = i/2;		
						}	
				}
				
			data1[i] = x;		
		}
}	

void heap :: max_heap(int x)

{
	int i;
	if(n2  == max)
		cout<<"ENTRIES ARE FULL"<<endl;
		
	else
		{
			n2++;
			for(i = n2;i >= 1;)
				{
					if(i == 1)
						break;
					
					if(x <= data2[i/2])
						break;
					
					else
						{
							data2[i] = data2[i/2];
							i = i/2;		
						}	
				}
				
			data2[i] = x;		
		}
}	

void heap :: display()

{
	cout<<"\nMINIMUM MARKS:"<<data1[1]<<endl;
	cout<<"MAXIMUM MARKS:"<<data2[1]<<endl;
}

int main()

{
	int no,marks;
	cout<<"Enter the number of students"<<endl;
	cin>>no;
	heap h(no);
	cout<<"Enter the marks"<<endl;
	
	for(int i = 0;i<no;i++)
		{
			cin>>marks;
			h.min_heap(marks);
			h.max_heap(marks);
		}
	
	h.display();	
		
	return 0;	
}
