
#include <stdio.h>
#include <stdlib.h>

//�жϻʺ��ڵ�ǰkλ���Ƿ�����Ҫ��(������,��ǰλ��)
bool isTrue(int* reslut, int locat)
{
	//ѭ����ǰλ��֮ǰ����
	for (int i = 0; i < locat; ++i)
	{	//�����ǰλ�ú�֮ǰ��һλ�������غ� �� б��Ϊ��1
		if ((reslut[i] == reslut[locat]) || (abs(reslut[i] - reslut[locat]) == abs(i - locat)))
			return false;
		return true;
	}
}


//n���㷨(�ʺ����,�������)
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