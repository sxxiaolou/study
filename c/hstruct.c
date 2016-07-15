#include "stdio.h"
#include "stdlib.h"
#include "hstruct.h"

int main(int argc, char const *argv[])
{
	hstruct *p = (hstruct*)malloc(sizeof(hstruct));
	p->a = 10;
	p->b = 11;
	p->c = 12;
	printf("%s\n", "hallo world!");
	printf("%d,%d,%d\n", p->a,p->b,p->c);
	return 0;
}