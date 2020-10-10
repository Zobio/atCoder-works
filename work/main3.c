#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void) {
	int n;
	scanf("%d", &n);
	bool yet[200001] = {};
	int count = 0;
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &now);
		yet[now] = true;
		while (yet[count])
		{
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}