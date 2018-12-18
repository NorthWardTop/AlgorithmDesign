#include <stdio.h>
#include <stdlib.h>

#define N		5		//��Ʒ��
#define M		100	//��������

typedef struct _Object
{
	float price;
	float wight;
	float v;
}Object;

//��������ʵ��,���ﰴ��С��������
void insert_sort(Object* a)//nΪ����a��Ԫ�ظ���
{
	//����N-1�ֲ������
	for (int i = 1; i < N; i++)
	{
		//�����ҵ�Ԫ��a[i]��Ҫ�����λ��
		int j = 0;
		while ((a[j].v > a[i].v) && (j<i))
		{
			j++;
		}
		//��Ԫ�ز��뵽��ȷ��λ��
		if (i != j)  //���i==j��˵��a[i]�պ�����ȷ��λ��
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
	float p[N] = { 20, 30, 66, 40, 60 };//�۸�
	float w[N] = { 10, 20, 30, 40, 50 };//����
	Object goods[N];
	//ʣ������,�����ܼ۸�,�������
	float m = M, tmpP = 0, result[N] = {};
	for (int i = 0; i < N; ++i)
	{
		goods[i].price = p[i];
		goods[i].wight = w[i];
		goods[i].v = goods[i].price / goods[i].wight;
	}

	insert_sort(goods);
	printf("�����Ľ��:�۸�,����	,���ر�\n");
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
	//��ӡ�������,�ܼ۸�
	printf("�����ܼ۸�:%f\n", tmpP);

	for (int i = 0; i < N; ++i)
	{
		printf("��%d����Ʒװ%f %%\n", i, result[i]*100);
	}
	system("pause");
	return 0;
}