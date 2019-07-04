#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[])
{
string data="";
unsigned int found;
string repl="";
cout<<argc<<endl;
ifstream is(argv[1]);
if(!is)
{
cout<<"File not found!"<<endl;
exit(1);
}
if(argc<4)
{
cout<<"Invalid Argument!"<<endl;
exit(1);
}
string a=argv[2];
while(is)
{
getline(is,data);
found=data.find(argv[2]);
while(data.find(argv[2])<string::npos)
{
data.replace(found,a.size(),argv[3]);
found=data.find((argv[2]));
}
repl=repl+data+"\n";
}
is.close();
ofstream os(argv[1]);
os<<repl;
os.close();
}
