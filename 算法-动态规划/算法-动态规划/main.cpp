#include <stdio.h>
#include <stdlib.h>

#define INF				(~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define MIN
#define N				7
#define Type			int					//费用类型
#define PART_ROW		5					//分5段
#define PART_COL		2					//每段最多2个邻接顶点

Type graph[N][N]
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

template<class T>
class Node
{
	int			vId;
	T			len;
	Node*		next;
public:
	init()
	{}
	Node(){}
	Node(int vId, T len, Node* next)
	{
		init();

	}
	~Node()
	{}
public:
};

template<class T>
class Graph
{
	Node<T>*	node[PART_ROW];	//图的所有链表头指针
	T			cost[N];		//决策过程中每个顶点到终点的费用
	int			rout[N];		//起点到终点的顶点编号(结果向量)
	int			path[N];		//
public:
	Graph(Node<T>* node, T* cost, int* rout, int* path) :node(node), cost(cost), rout(ro)
	{
		Node<T>* pNode = new Node<T>[N];
		for (int i = 0; i < N; ++i)
			pNode[i].init(i,);   
	}
	~Graph()
	{
		delete[]pNode;
	}
};

template<class T>
void initGrpaph(Node<T>* node)
{

}
 
//最短寻路算法
template < class T>
T findShortPath(Node<T>* node, int* rout)
{

}



int main()
{
	Node<int> node




	system("pause");
	return 0;
}