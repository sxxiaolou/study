#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/malloc.h>
#include <time.h>


typedef int QElemType;
#define MAXSIZE 5

typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;

}SqQueue;


int
InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return 1;
}

int
QueueLength(SqQueue *Q)
{
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}

int
PushQueue(SqQueue *Q,QElemType e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)
	{
		return -1;
	}

	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return 1;
}

int
PopQueue(SqQueue *Q,QElemType *e)
{
	if(Q->front == Q->rear)
	{
		return -1;
	}

	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return 1;
}

void Exchg(int *a,int *b)
{
	printf("%p   %d\n", &a,*a);
	printf("%p   %d\n", &b,*b);
}

int main(int argc, char const *argv[])
{
	//队
	SqQueue *Q;
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);

	PushQueue(Q,100);
	QElemType *e = (QElemType*)malloc(sizeof(QElemType));
	PopQueue(Q,e);
	printf("%d\n", *e);

	int x = 5;
	int y = 6;
	printf("%p   %d\n", &x,x);
	printf("%p   %d\n", &y,y);
	int *i = &x;
	int *j = &y;
	*i = 9;
	*j = 10;
	printf("%p   %d\n", &x,x);
	printf("%p   %d\n", &y,y);
	printf("%p   %d\n", &i,*i);
	printf("%p   %d\n", &j,*j);
	Exchg(i,j);
	return 0;
}

