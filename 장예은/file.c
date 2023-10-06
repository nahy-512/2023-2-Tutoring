#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int n, m, count = 0;
	int s = 0;
	int sum = 0;
	int result[100];
	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = m; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i / j == j && i % j == 0)
			{
				s = 1;
				result[count] = i;
				count++;
				sum += i;
			}
		}
	}
	if (s == 0)
		printf("-1");
	else
		printf("%d \n%d", result[0],sum);
}