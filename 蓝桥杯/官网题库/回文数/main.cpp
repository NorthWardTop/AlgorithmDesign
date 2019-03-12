#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int arr[4]={0};
	for(int i=1000;i<=9999;++i)
	{
		arr[0]=i/1000%10;
		arr[1]=i/100%10;
		arr[2]=i/10%10;
		arr[3]=i%10;
		if(arr[0]==arr[3] && arr[1]==arr[2])
			cout<<i<<endl;
	}
	
	return 0;
}
