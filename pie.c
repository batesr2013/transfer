#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[])
{
	if(argc < 2)
	{
		return 0;
	}
	int N = atoi(argv[1]);
	int T = atoi(argv[2]);
	int i = 0;
	int k = 0;
	double sum = 3.0;
	char output[1050];
	output[0] = '3';
	output[1] = '.';
	//double power = 1;
	int amount = N / T;
	double accum = 3.0;
	
	if (N < T)
	{
		printf("N less than T");
		return 0;
	}
	
	if(N > 1040)
	{
		printf(" number surpasses allowed value by code.");
		return 0;
	}

	for(j=0;j<T;j++)
	{
		int pipe1[2];
		int r;
		r = pipe(pipe1);
		if (r<0)
		{
			fprintf(stderr, "pope failed\n\n");
			exit(2);
		}
		int pid = fork();
		if (pid > 0)
		{
			r = fwrite(pipe1[1], N, T, j);
			if (r<0)
			{
				fprintf(stderr, "parent: write failed\n\n");
			}
			printf("parent wrote %d %d and %d to pipe", N, T, j);
		}
		else if (pid == 0)
		{
			r = fread(pipe1[0], N, T, j);
			//if (j=0)
			//{
				//double accum = 3.0;
			//}
			//else
			//{
				//double accum = 0.0;
			//}
			for (i=((amount*j)-amount);i<(amount*j);i++)
			{
			
				accum = accum + k*4/((2.0*i)*(2.0*i+1.0)*(2.0*i+2.0));
				printf("The approximation of pi with N=%d and T=%d processes is %f ",N ,T , accum);
			}
		}
	}
	
	for (i=1;i < 14;i++)
	{
		if (i % 2 == 0)
		{
			k = -1;
		}
		else
		{
			k = 1;
		}
		//power = power * 10;
		sum = sum + k*4/((2.0*i)*(2.0*i+1.0)*(2.0*i+2.0));
		//double count2 = count;
		//double ten = 10.0;
		//if (count > 2)
		//{
			//printf(" %f ", sum);
			//sum = sum * power;
			//printf(" %f ", sum);
			//int digit = sum;
			//sum = sum - digit;
			//printf(" %f ", sum);
			//sum = sum / power;
			//printf(" %f ", sum);
			//digit = digit + 48;
		
			//output[count+1] = digit;
			//printf(" %f ", sum);
		//}
	}
	//output[count+1] = 0;
	
	//printf("The approximation of pi with N=%d and T=%d processes is %f ",N ,T , sum);
}
