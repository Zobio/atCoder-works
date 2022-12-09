#import <algorithm>
long p = 1, q = 1, x, a, b;
main()
{
	scanf("%d", &x);
	while (~scanf("%d%d", &a, &b))
	{
		x = std::max((p + a - 1) / a, (q + b - 1) / b);
		p = x * a;
		q = x * b;
	}
	printf("%ld", p + q);
}