#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fb(int n)
{
	int f1=1,f2=1,f3;
	for(int i=2;i<n;++i)
	{
		f3=(f1+f2)%10007;
//		f3=f1+f2;
//		if(f3>=10007)
//			f3%=10007;
		f1=f2;
		f2=f3;
		
		
	}
	return f3;
} 


int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	printf("%d", fb(n));
	
	return 0;
}
