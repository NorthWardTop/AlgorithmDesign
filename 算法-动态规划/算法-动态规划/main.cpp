#include <stdio.h>
#include <stdlib.h>

#define MAX
#define MIN
#define N		10
#define Type	int

template<class T>
class Node
{
	int			vId;
	T			len;
	struct _Node* next;
};

Node<Type> node[N];	//图的所有链表头
Type		cost[N];
int			rout[N];
int			path[N];


int main()
{
	

	system("pause");
	return 0;
}