
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/******
��������
��������n��ʮ��������������������Ƕ�Ӧ�İ˽�������

�����ʽ
��������ĵ�һ��Ϊһ��������n ��1<=n<=10����
����������n�У�ÿ��һ����0~9����д��ĸA~F��ɵ��ַ�������ʾҪת����ʮ��������������
	ÿ��ʮ�����������Ȳ�����100000��

�����ʽ
�������n�У�ÿ��Ϊ�����Ӧ�İ˽�����������

������ע�⡿
���������ʮ��������������ǰ��0������012A��
��������İ˽�����Ҳ������ǰ��0��

��������
����2
����39
����123ABC

�������
����71
����4435274

��������ʾ��
�����Ƚ�ʮ��������ת����ĳ������������ĳ������ת���ɰ˽��ơ�
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
//    int prev_i=a-1>=0?a-1:0;//Խ������ 
//    int next_i=a+1<n?a-1:a;
//    
//    
//    while(index==0||index==n)
//    {
//    	int prev=abs(curr-arr[prev_i]);
//	    int next=abs(curr-arr[next_i]);
//	    if(prev<next)//ǰ��С
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



