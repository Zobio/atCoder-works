#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	long long a[n];
	long long b[n];
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		if(a[i] % 2 != b[i] % 2) {
			ans += (b[i] - a[i] + 1) / 2 * (a[i] + b[i]);
		}else{
			ans += (b[i] - a[i] + 1) / 2 * (a[i] + b[i]) + (a[i] + b[i]) / 2;
		}
	}
	printf("%lld\n", ans);
}