#include "stdio.h"
#include "stdlib.h"

double maxinum = 0;

int main(int argc, char const *argv[])
{
	/* code */
	double blocksize[] = {1024*1024,1024,1};
	int i,count;
	for (int i = 0; i < 3; ++i)
	{
		for (int count = 1; i < count; ++count)
		{
			void *block = malloc(maxinum + blocksize[i] * count);
			if(block)
			{
				maxinum = maxinum + blocksize[i]*count;
				free(block);
			}
			else
			{
				break;
			}
			printf("maxinum malloc size = %lf bytes\n", maxinum);
		}
	}
	printf("maxinum malloc size = %lf bytes\n", maxinum);
	return 0;
}