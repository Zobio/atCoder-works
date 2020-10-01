#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n = 0;
	scanf("%d", &n);
	char a[200000][11];
	for(int i = 0; i < n; i++) {
		scanf("%s", a[i]); 
	}
	qsort(a, n, 11, *strcmp);
	int max = 0;
	int nums[200000] = {};
	int m = 0;
	for(int i = 0; i < n - 1; i++) {
		if (!strcmp(a[i], a[i + 1]))
		nums[m]++;
		else
		m++;
	}
	for(int i = 0; i < n; i++) {
		if(max < nums[i])
		max = nums[i];
	}
	int mayAns = 0;
	for(int i = 0; i < n - 1; i++) {
		if (!strcmp(a[i], a[i + 1]))
			mayAns++;
			else
			mayAns = 0;
			if(mayAns == max){
				printf("%s\n", a[i]);
				if(max == 0 && i == n - 2) {
					printf("%s\n", a[i + 1]);
				}
			}
	}
	return 0;
}