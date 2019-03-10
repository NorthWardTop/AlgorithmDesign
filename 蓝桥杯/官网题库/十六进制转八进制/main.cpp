
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/******
问题描述
　　给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
　　输入的第一行为一个正整数n （1<=n<=10）。
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，
	每个十六进制数长度不超过100000。

输出格式
　　输出n行，每行为输入对应的八进制正整数。

　　【注意】
　　输入的十六进制数不会有前导0，比如012A。
　　输出的八进制数也不能有前导0。

样例输入
　　2
　　39
　　123ABC

样例输出
　　71
　　4435274

　　【提示】
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/ 


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <list>
using namespace std;

string hex_to_bin(const string& hex)
{
	
}

string bin_to_oct(const string& bin)
{
	 
}

#define INF 1000001

int main(int argc, char *argv[]) {
	//int n,a,tmp;
//	int len=0; 
//    cin>>n>>a;
//    
//    int* arr=new int[n];
//    for(int i=0;i<n;++i)
//    {
//        cin>>arr[i];
//    }

//    int curr=a;
//    int prev_i=a-1>=0?a-1:0;//越界问题 
//    int next_i=a+1<n?a-1:a;
//    
//    
//    while(index==0||index==n)
//    {
//    	int prev=abs(curr-arr[prev_i]);
//	    int next=abs(curr-arr[next_i]);
//	    if(prev<next)//前面小
//		{
//			len+=prev;
//			index--;
//			prev_i--;
//		} 
//		else
//		{
//			len+=next;
//			index++;
//			next_i++;
//		}
//    }
//    cout<<len;


	list<int> arr;
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		arr.push_back(i+1);
	
	
	for( ;arr.size()!=1;)
	{
		int tmp=arr.back();
		cout<<tmp<<' ';
		arr.pop_back();
		tmp=arr.back();
		arr.pop_back();
		arr.push_front(tmp);
	}
    
	return 0;
}



