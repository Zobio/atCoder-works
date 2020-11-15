#include <stdio.h>

int main()
{
	int i, N, S, T, P;
	long long W, Q[200002] = {};
	scanf("%d %lld", &N, &W);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &S, &T, &P);
		Q[S] += P;
		Q[T] -= P;
	}
	
	long long tmp = 0;
	for (i = 0; i <= 200000; i++) {
		tmp += Q[i];
		if (tmp > W) break;
	}
	if (i <= 200000) printf("No\n");
	else printf("Yes\n");
	fflush(stdout);
	return 0;
}