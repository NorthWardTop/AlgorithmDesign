#include <stdio.h>
#include <stdlib.h>

//ѭ���������С
void maxMin(int* a, int *e_max, int* e_min, int n)
{
	*e_min = a[0];
	*e_min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (*e_max < a[i])
			*e_max = a[i];
		if (*e_min>a[i])
			*e_min = a[i];
	}
}

//�ݹ��������С(����,�������, ������С, ��λ�±�, ��λ�±�)
void maxMin(int* a, int& max, int& min, int low, int high)
{
	int tmpMax[2], tmpMin[2];
	if (high - low <= 1)
	{
		max = a[low] <= a[high] ? a[high] : a[low];
		min = a[low] <= a[high] ? a[low] : a[high];
	}
	else
	{
		int mid = (low + high) >> 1;	//����2
		maxMin(a, tmpMax[0], tmpMin[0], low, mid);	//��һ�������С
		maxMin(a, tmpMax[1], tmpMin[1], mid + 1, high);		//�ڶ��������С
		max = tmpMax[0] >= tmpMax[1] ? tmpMax[0] : tmpMax[1];
		min = tmpMin[0] <= tmpMin[1] ? tmpMin[0] : tmpMin[1];
	}
}

//�ϲ�һ��������������򲿷�(
template <class T>
void merge(T* a, int low, int mid, int high)
{
	T* buf = new T[high - low + 1];
	int i = low, j = mid + 1, k = 0;	//��������ĳ�ʼ�±�
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
			buf[k++] = a[i++];
		else
			buf[k++] = a[j++];
	}
	//�Ƿ񳬹�mid
	if (i > mid)	//�󲿷�ʣ��
	{
		while (j <= high)
			buf[k++] = a[j++];
	}
	else		//ǰ����ʣ��
	{
		while (i <= mid)
			buf[k++] = a[i++];
	}
	k = 0;
	for (i = low; i <= high; ++i)
		a[i] = buf[k++];
}

//���ַ��ݹ�����
template <class T>
void mergeSort(T* a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) >> 1;
		mergeSort<T>(a, low, mid);
		mergeSort<T>(a, mid + 1, high);
		merge<T>(a, low, mid, high);
	}
}

int main()
{
	int  max, min;
	int a[10] = { 9, 3, 6, 2, 1, 8, 4, 5, 7, 23 };
	maxMin(a, max, min, 0,9);
	printf("��������������%d,��С������%d\n", max, min);
	mergeSort<int>(a, 0, 9);
	printf("����������Ϊ:");
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}