#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	long n;
	long w;
	scanf("%d", &n);
	scanf("%d", &w);
	long s[n];
	long t[n];
	long p[n];
	long water[200001] = {};
	bool yet[200001] = {};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		scanf("%d", &t[i]);
		scanf("%d", &p[i]);
		for (int j = s[i]; j < t[i]; j++)
		{
			water[j] += p[i];
			yet[j] = true;
		}
	}

	for(int i = 0; i < 200001 && yet; i++) {
		if (water[i] > w)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}