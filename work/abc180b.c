#include<stdio.h>
#include<math.h>

int main(void) {
	int n;
	scanf("%d", n);
	int p[n];
	for(int i = 0; i < n; i ++) {
		scanf("%d", p[i]);
	}
	long sum = 0;
	for(int i = 0; i < n; i++) {
		if(p[i] < 0)
		sum += p[i] * -1;
		else
		sum += p[i];
		printf("now is %d : %d", i, sum);
	}
	printf("%d", sum);
	sum = 0;
	for(int i = 0; i < n; i++) {
		sum += p[i] * p[i];
	}
	printf("%d", pow(sum, 0.5));
	sum = 0;
	for(int i = 0; i < n; i++) {
		if(sum < p[i])
		sum = p[i];
	}
	printf("%d", sum);
	return 0;
}