#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	if(argc < 2)
	{
		return 0;
	}
	int N = atoi(argv[1]);
	int T = atoi(argv[2]);
	int count = 1;
	int k = 0;
	//double sum = 3.0;
	char output[N+2] = NULL;
	output[0] = 3;
	output[1] = .;

	for (count=0;count < 100;count++)
	{
		if (count % 2 == 0)
		{
			k = -1;
		}
		else
		{
			k = 1;
		}
		//sum = sum + k*4/((2.0*count)*(2.0*count+1.0)*(2.0*count+2.0));
		
		
	}
	printf(" %f ", sum);
}
