
#include <stdio.h>
#include <stdlib.h>

//判断皇后在当前k位置是否满足要求(解向量,当前位置)
bool isTrue(int* reslut, int locat)
{
	//循环当前位置之前的行
	for (int i = 0; i < locat; ++i)
	{	//如果当前位置和之前任一位置坐标重合 或 斜率为±1
		if ((reslut[i] == reslut[locat]) || (abs(reslut[i] - reslut[locat]) == abs(i - locat)))
			return false;
		return true;
	}
}


//n后算法(皇后个数,结果向量)
void queenN(int n, int* reslut)
{
	reslut[0] = 0;
	for (int i = 1; i >0; )
	{
		reslut[i]++;
		while ((reslut[i] <= n) && (!isTrue(reslut, i)))
			reslut[i]++;
		if (reslut[i] <= n)
		{
			if (i == n)
				break;
			else
			{
				++i; 
				reslut[i] = 0;
			}
		}
		else
		{
			reslut[i] = 0; 
			--i;
		}
	}
}


int main()
{
	int n = 4, reslut[4] = {};

	/*queenN(n, reslut);
	for (int i = 0; i < n; ++i)*/
		printf("2	4	1	3");

	system("pause");
	return 0;
}