#include <stdio.h>
#include <stdlib.h>

#define INF				(~(0x1<<31))        // ���ֵ(��0X7FFFFFFF)
#define MIN
#define N				7
#define Type			int					//��������
#define PART_ROW		5					//��5��
#define PART_COL		2					//ÿ�����2���ڽӶ���

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
	Node<T>*	node[PART_ROW];	//ͼ����������ͷָ��
	T			cost[N];		//���߹�����ÿ�����㵽�յ�ķ���
	int			rout[N];		//��㵽�յ�Ķ�����(�������)
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
 
//���Ѱ·�㷨
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