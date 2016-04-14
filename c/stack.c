#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/malloc.h>
#include <time.h>


typedef int SElemType;
int MAXSIZE = 5;

typedef struct SqStack
{
	SElemType data[5];
	int top;

}SqStack;


int
Push(SqStack *S, SElemType e)
{
	if(S->top == MAXSIZE -1)
	{
		return -1;
	}
	S->top++;
	printf("Push %d\n", S->top);
	S->data[S->top]=e;
	printf("Push %d\n", S->data[S->top]);
	return 1;
}

int
Pop(SqStack *S,SElemType *e)
{
	printf("Pop %d\n", S->top);
	if(S->top==-1)
	{
		return -1;
	}
	*e=S->data[S->top];

	printf("Pop %d\n", *e);
	printf("Pop %p\n",&e);
	S->top --;
	return 1;
}

int main(int argc, char const *argv[])
{
	//栈
	SqStack *S;
	S = (SqStack*)malloc(sizeof(SqStack));
	S->top = -1;
	Push(S,100);
	SElemType *e = (SElemType*)malloc(sizeof(SElemType));
	printf("%p\n",&e);
	Pop(S,e);
	printf("%p\n",&e);
	printf("%d\n", *e);

	return 0;
}

