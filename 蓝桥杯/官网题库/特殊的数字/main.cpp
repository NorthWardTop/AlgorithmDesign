#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int arr[3];
	for(int i=100;i<=999;++i)
	{
		arr[0]=i/100%10;
		arr[1]=i/10%10;
		arr[2]=i%10;
		if(pow(arr[0],3)+pow(arr[1],3)+pow(arr[2],3)==i)
			cout<<i<<endl;
	}
	
	return 0;
}
