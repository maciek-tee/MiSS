#include <stdio.h>

void accumulate(int *total, int value);

int main(int argc, char *argv[])
{
	char *d = argv[1];
	int number;
	int totalSum = 0;
	int totalSquares = 0;
	int n = 0;
	double average;
	double averageSquares;
	double averageSquared;
	double variance;

	while (scanf("%d", &number) > 0)
	{
		accumulate(&totalSum, number);
		accumulate(&totalSquares, number * number);
		n++;
	}

	average = ((double)totalSum) / n;
	averageSquares = ((double)totalSquares) / n;
	averageSquared = average * average;
	variance = averageSquares - averageSquared;

	printf("%f\n", average);
	printf("%f", variance);

	return 0;
}

void accumulate(int *total, int value)
{
	*total += value;
}