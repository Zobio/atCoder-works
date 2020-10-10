#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

int main(void) {
	srand((unsigned int)time(NULL));
	int n;
	scanf("%d", &n);
	bool yet[200001];
	int count = 0;
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		now = rand() % 10;
		printf("%d\n", now);
		yet[now] = true;
		while (yet[count])
		{
			count++;
		}
		printf("ans:%d\n", count);
	}
	return 0;
}