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
	double sum = 0.0;
	char output[1050];
	output[0] = '3';
	output[1] = '.';
	if(N > 1040)
	{
	printf(" number surpasses allowed value by code.");
	}

	for (count=0;count < 1000;count++)
	{
		if (count % 2 == 0)
		{
			k = -1;
		}
		else
		{
			k = 1;
		}
		sum = sum + k*4/((2.0*count)*(2.0*count+1.0)*(2.0*count+2.0));
		sum = sum *(10^(count));
		int digit = sum;
		sum = sum - digit;
		sum = sum /(10^(count));
		digit = digit + 48;
		output[count+1] = digit;
		
	}
	
	printf(" %s ", output);
}
