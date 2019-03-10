#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double r,area;
	scanf("%lf",&r);
	area=3.14159265358979323*r*r;
//	area+=0.0000005; 
	printf("%.7lf",area);
	
	return 0;
}
