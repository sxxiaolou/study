#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/malloc.h>
#include <time.h>


typedef struct Node
{
	int data;
	struct Node *next;

}Node;

typedef struct Node *LinkList;

void
create_list_head(LinkList L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	L->next = NULL;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		printf("%d\n",p->data );
		p->next = L->next;
		L->next = p;
	}

}

int main(int argc, char const *argv[])
{
	//链表的实现 和指针作为实参和形参的意义
	LinkList L;
	L = (LinkList)malloc(sizeof(Node));
	create_list_head(L,100);


	return 0;
}

