#include <iostream>
#include <algorithm> 
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char *argv[]) {
	int n=0;
	scanf("%d",&n);
	short* arr=(short*)malloc(sizeof(short)*n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;++i)
		printf("%d ",*(arr+i));
		
	if(arr!=NULL)
		free(arr); 
	return 0;
}
