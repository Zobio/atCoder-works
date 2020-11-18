#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
	int n;
	int64_t ans = 0;
	int64_t now = 0;
	int64_t maxMove = 0;
	int64_t move = 0;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		move += a[i];
		now += move;
		if (now + maxMove > ans){
			ans = now + maxMove;
		}
		if (maxMove < move) {
			maxMove = move;
		}
	}
	printf("%" PRId64 "\n", ans);
}