#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *p, const void *q);

int main(void) {
	int n;
	scanf("%d", &n);
	int p[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", p[i]);
	}
	int count = 0;
	int nCopy =n;
	for(int a = 0; a < n; a++) {
	int pCopy[n - a];
	memcpy(pCopy, p[a], sizeof(p));
	qsort(pCopy, sizeof(pCopy) / sizeof(int), sizeof(int), cmp);
	for(int ru = 0; ru < n-a; ru++) {
		printf("%d\n", pCopy[ru]); 
	}
	if(p[a] <= pCopy[n - a])
	count++;
	}
	printf("%d", count);
}

int cmp(const void *p, const void *q)
{
	return *(int *)p - *(int *)q;
}