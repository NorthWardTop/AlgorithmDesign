#include <stdio.h>
#include <stdlib.h>

#define INF				(~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define MIN
#define N				7
#define Type			int					//费用类型
#define PART_ROW		2					//分5段
#define PART_COL		5					//每段最多2个邻接顶点

Type graphArr[N][N]
{
		/*A*//*B*//*C*//*D*//*E*//*F*//*G*/
	/*A*/{ 0, 4, 5, 8, INF, INF, INF },
	/*B*/{ INF, 0, INF, 6, 6, INF, INF },
	/*C*/{ INF, INF, 0, 5, INF, 7, INF },
	/*D*/{ INF, INF, INF, 0, 8, 9, 9 },
	/*E*/{ INF, INF, INF, INF, 0, INF, 5 },
	/*F*/{ INF, INF, INF, INF, INF, 0, 4 },
	/*G*/{ INF, INF, INF, INF, INF, INF, 0 }
};

typedef struct _Node
{
	int					id;
	struct _Node*		next;
}Node;

Node		node[PART_COL];	//图的所有链表头指针
Type		cost[N];		//决策过程中每个顶点到终点的费用
int			path[N];		//路径选择

//初始化段内邻接链,和宏PATH_ROW有关()
void initGraph()
{
	node[0].id = 0;
	node[0].next = NULL;
	
	node[1].id = 1;
	node[1].next = (Node*)malloc(sizeof(Node));
	node[1].next->id = 2;
	node[1].next->next = NULL;

	node[2].id = 3;
	node[2].next = NULL;

	node[3].id = 4;
	node[3].next = (Node*)malloc(sizeof(Node));
	node[3].next->id = 5;
	node[3].next->next = NULL;

	node[4].id = 6;
	node[4].next = NULL;

	//int num = 0;
	//for (int i = 0; i < PART_COL; ++i)
	//{
	//	node[i].id = num;
	//	num++;
	//	node[i].next = NULL;
	//	for (int j = 1; j < PART_COL/*&& 第i列j个后有邻接顶点*/; ++j)
	//	{
	//		node[i].next = (Node*)malloc(sizeof(Node));
	//		node[i].next->next->id = num;
	//		num++;
	//		node[i].next->next->next = NULL;
	//	}
	//}

	for (int i = 0; i < N; ++i)
	{
		cost[i] = INF;
		path[i] = -1;
	}
	//设定终点id为6
	path[PART_COL - 1] = 6;
	//设定初始cost为0
	cost[PART_COL - 1] = 0;
}

//动态寻最短路径
void findPath()
{
	//段见循环,共PART_COL段(除去最后一个点6)
	for (int i = PART_COL - 1; i >= 0; --i)
	{	//段内循环,node[i-1]为头开始的链表(循环的是当前i结点列的前列
		for (Node* pCurrNode = &node[i-1]; pCurrNode != NULL; pCurrNode = pCurrNode->next)
		{	//如果当前结点到i段所选点长度+i段到终点长度(cost[i]) < 前段结点到终点长度(cost[i-1])
			if (graphArr[pCurrNode->id][path[i]] + cost[i] < cost[i - 1])
			{
				//更新i-1段到终点花费为较短值
				cost[i - 1] = graphArr[pCurrNode->id][path[i]] + cost[i];
		//		cost[i - 1] = graphArr[]
				//更新i-1段路径选择
				path[i - 1] = pCurrNode->id;
			}
		}
	}
	//由于pCurrNode修改了node[4].next的值,现将其复原
	node[PART_COL - 1].next = NULL;
}

//释放图,宏PATH_ROW有关()
void delGraph()
{
	for (int i = 0; i < PART_COL;++i)
	{	//最多有两个节点,只需要判断下节点
		if (node[i].next)
		{
			free(node[i].next);
			node[i].next = NULL;
		}
			
	}
}

//打印路径
void printPath()
{
	puts("最短路径选择为:");
	for (int i = 0; i < N&&path[i]!=-1; ++i)
		printf("%d --> ", path[i]);
	printf("NULL\n");
	printf("最短长度为: %d\n", cost[0]);
}


int main()
{
	initGraph();
	findPath();
	printPath();
	delGraph();

	system("pause");
	return 0;
}


//
//template<class T>
//class Node
//{
//	int			vId;
//	T			len;
//	Node*		next;
//public:
//	init()
//	{}
//	Node(){}
//	Node(int vId, T len, Node* next)
//	{
//		init();
//
//	}
//	~Node()
//	{}
//public:
//};
//
//template<class T>
//class Graph
//{

//public:
//	Graph(Node<T>* node, T* cost, int* rout, int* path) :node(node), cost(cost), rout(ro)
//	{
//		Node<T>* pNode = new Node<T>[N];
//		for (int i = 0; i < N; ++i)
//			pNode[i].init(i,);   
//	}
//	~Graph()
//	{
//		delete[]pNode;
//	}
//};
//
//template<class T>
//void initGrpaph(Node<T>* node)
//{
//
//}
// 
////最短寻路算法
//template < class T>
//T findShortPath(Node<T>* node, int* rout)
//{
//
//}
//
//
//
//int main()
//{
//	Node<int> node
//
//
//
//
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <iostream>
//
//#define MAX 100  
//#define n 12   /*顶点数*/
//#define k 5  /*段数*/
//using namespace std;
//int c[n][n];
//
//
//void init(int cost[]) //初始化图
//{
//	int i, j;
//	for (i = 0; i < 13; i++)
//	{
//		for (j = 0; j < 13; j++)
//		{
//			c[i][j] = MAX;
//		}
//	}
//	c[1][2] = 9;	c[1][3] = 7;	c[1][4] = 3;	c[1][5] = 2;	c[2][6] = 4;	c[2][7] = 2;	c[2][8] = 1;
//	c[3][6] = 2;	c[3][7] = 7;	c[4][8] = 11;	c[5][7] = 11;	c[5][8] = 8;	c[6][9] = 6;	c[6][10] = 5;
//	c[7][9] = 4;	c[7][10] = 3;	c[8][10] = 5;	c[8][11] = 6;	c[9][12] = 4;	c[10][12] = 2; c[11][12] = 5;
//}
//
//void fgraph(int cost[], int path[], int d[]) //使用向前递推算法求多段图的最短路径
//{
//	int r, j, temp, min;
//	for (j = 0; j <= n; j++)
//		cost[j] = 0;
//	for (j = n - 1; j >= 1; j--)
//	{
//		temp = 0;
//		min = c[j][temp] + cost[temp];       //初始化最小值
//		for (r = 0; r <= n; r++)
//		{
//			if (c[j][r] != MAX)
//			{
//				if ((c[j][r] + cost[r]) < min)       //找到最小的r
//				{
//					min = c[j][r] + cost[r];
//					temp = r;
//				}
//			}
//		}
//		cost[j] = c[j][temp] + cost[temp];
//		d[j] = temp;
//	}
//	path[1] = 1;
//	path[k] = n;
//	for (j = 2; j < k; j++)
//		path[j] = d[path[j - 1]];
//}
//
//void bgraph(int bcost[], int path1[], int d[])//使用向后递推算法求多段图的最短路径
//{
//	int r, j, temp, min;
//	for (j = 0; j <= n; j++)
//		bcost[j] = 0;
//	for (j = 2; j <= n; j++)
//	{
//		temp = 12;
//		min = c[temp][j] + bcost[temp];           //初始化最小值
//		for (r = 0; r <= n; r++)
//		{
//			if (c[r][j] != MAX)
//			{
//				if ((c[r][j] + bcost[r]) < min)        //找到最小的r
//				{
//					min = c[r][j] + bcost[r];
//					temp = r;
//				}
//			}
//		}
//		bcost[j] = c[temp][j] + bcost[temp];
//		d[j] = temp;
//	}
//	path1[1] = 1;
//	path1[k] = n;
//	for (int i = 4; i >= 2; i--)
//	{
//		path1[i] = d[path1[i + 1]];
//	}
//}
//
//void main()
//{
//	int i = 0;
//	int cur = -1;
//	int cost[13], d[12], bcost[13];
//	int path[k];
//	int path1[k];
//	cout << "\t\t\t动态规划解多段图问题" << endl;
//	cout << "\n\n";
//	init(cost);
//	fgraph(cost, path, d);
//	cout << "输出使用向前递推算法后的最短路径:\n\n";
//	for (int i = 1; i <= 5; i++)
//	{
//		cout << path[i] << "   ";
//	}
//	cout << "\n";
//	cout << endl << "最短路径为长度:" << cost[1] << endl;
//	cout << "\n";
//	cout << "\n输出使用向后递推算法后的最短路径:\n\n";
//	bgraph(bcost, path1, d);
//	for (i = 1; i <= 5; i++)
//	{
//		cout << path1[i] << "   ";
//	}
//	cout << "\n";
//	cout << endl << "最短路径为长度:" << bcost[12] << endl;
//	cout << "\n";
//}


