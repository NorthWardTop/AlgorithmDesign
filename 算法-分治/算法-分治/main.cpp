#include <stdio.h>
#include <stdlib.h>

//循环求最大最小
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

//递归求最大最小(数组,返回最大, 返回最小, 低位下标, 高位下标)
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
		int mid = (low + high) >> 1;	//除以2
		maxMin(a, tmpMax[0], tmpMin[0], low, mid);	//第一组最大最小
		maxMin(a, tmpMax[1], tmpMin[1], mid + 1, high);		//第二组最大最小
		max = tmpMax[0] >= tmpMax[1] ? tmpMax[0] : tmpMax[1];
		min = tmpMin[0] <= tmpMin[1] ? tmpMin[0] : tmpMin[1];
	}
}

//合并一个数组的两个有序部分(
template <class T>
void merge(T* a, int low, int mid, int high)
{
	T* buf = new T[high - low + 1];
	int i = low, j = mid + 1, k = 0;	//三个数组的初始下标
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
			buf[k++] = a[i++];
		else
			buf[k++] = a[j++];
	}
	//是否超过mid
	if (i > mid)	//后部分剩余
	{
		while (j <= high)
			buf[k++] = a[j++];
	}
	else		//前部分剩余
	{
		while (i <= mid)
			buf[k++] = a[i++];
	}
	k = 0;
	for (i = low; i <= high; ++i)
		a[i] = buf[k++];
}

//二分法递归排序
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
	printf("数组中最大的数是%d,最小的数是%d\n", max, min);
	mergeSort<int>(a, 0, 9);
	printf("排序后的数组为:");
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}