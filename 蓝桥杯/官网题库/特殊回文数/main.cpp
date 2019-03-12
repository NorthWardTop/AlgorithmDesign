#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define _DEBUG 0

list<int> arr;

void print()
{
	for(list<int>::iterator i=arr.begin();i!=arr.end();++i)
		cout<<*i<<endl;
#if _DEBUG
	cout<<"count: "<<arr.size()<<endl;
#endif
}

void five_bit(int n)
{
	for(int i=999;i>=0;--i)
	{
		int a=0,b=0,c=0;
		int tmp=0;
		a=i%10;
		b=i/10%10;
		c=i/100%10;
		if((a+b)*2+c==n && a!=0 )
		{
//#if _DEBUG
//			cout<<++cnt<<':';
//#endif
			//cout<<a<<b<<c<<b<<a<<endl; 
			tmp=a*10000+b*1000+c*100+b*10+a;
			arr.push_back(tmp); 
		}
	}
}

void six_bit(unsigned int n)
{
	for(int i=999;i>=0;--i)
	{
		int a=0,b=0,c=0;
		int tmp=0;
		a=i%10;
		b=i/10%10;
		c=i/100%10;
		//a!=0 || (a!=0 && b==0) ||
		if((a+b+c)*2==n && a!=0 )
		{
//#if _DEBUG
//			cout<<++cnt<<':';
//#endif
			//cout<<a<<b<<c<<c<<b<<a<<endl; 
			tmp=a*100000+b*10000+c*1000+c*100+b*10+a;
			arr.push_back(tmp);
		}
	}
}

int main(int argc, char *argv[]) {
	unsigned int n=0;

#if _DEBUG
	for(;;)
	{
		arr.clear();
		cin>>n;
		five_bit(n); 
		six_bit(n);
		arr.sort();
		print(); 
	}
#else
	cin>>n;
	five_bit(n);
	six_bit(n);
	arr.sort();
	print();
#endif

	
	return 0;
}







