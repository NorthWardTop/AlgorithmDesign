#include <stdio.h>
#include <stdlib.h>

#define N		5		//物品数
#define M		100	//背包容量

typedef struct _Object
{
	float price;
	float wight;
	float v;
}Object;

//插入排序实现,这里按从小到大排序
void insert_sort(Object* a)//n为数组a的元素个数
{
	//进行N-1轮插入过程
	for (int i = 1; i < N; i++)
	{
		//首先找到元素a[i]需要插入的位置
		int j = 0;
		while ((a[j].v > a[i].v) && (j<i))
		{
			j++;
		}
		//将元素插入到正确的位置
		if (i != j)  //如果i==j，说明a[i]刚好在正确的位置
		{
			Object temp = a[i];
			for (int k = i; k > j; k--)
			{
				a[k] = a[k - 1];
			}
			a[j] = temp;
		}
	}
}


int main()
{
	float p[N] = { 20, 30, 66, 40, 60 };//价格
	float w[N] = { 10, 20, 30, 40, 50 };//重量
	Object goods[N];
	//剩余质量,包的总价格,结果向量
	float m = M, tmpP = 0, result[N] = {};
	for (int i = 0; i < N; ++i)
	{
		goods[i].price = p[i];
		goods[i].wight = w[i];
		goods[i].v = goods[i].price / goods[i].wight;
	}

	insert_sort(goods);
	printf("排序后的结果:价格,重量	,价重比\n");
	for (int i = 0; i < N; ++i)
	{
		printf("%f,%f,%f\n", 
			goods[i].price, goods[i].wight,goods[i].v);
	}
	
	for (int i = 0; i < N; ++i)
	{
		if (goods[i].wight <= m)
		{
			result[i] = 1;
			m -= goods[i].wight;
			tmpP += goods[i].price;
		}
		else
		{
			result[i] = m / goods[i].wight;
			tmpP += goods[i].price*result[i];
			break;
		}
	}
	//打印结果向量,总价格
	printf("背包总价格:%f\n", tmpP);

	for (int i = 0; i < N; ++i)
	{
		printf("第%d个物品装%f %%\n", i, result[i]*100);
	}
	system("pause");
	return 0;
}