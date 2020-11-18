#include <stdio.h>
#include <inttypes.h>

	int
	main(void)
{
	long long n;
	int p[3] = {}; //amari 0, 1, 2 no kazu
	int tmp = 0;
	int sum = 0;
	int length = 0;
	scanf("%" SCNd64, &n);
	long long oldN = n;
	 do {
		p[(n % 10) % 3]++;
		n /= 10;
		length++;
	 } while (n >= 10);
	 if(oldN >= 10) {
	 p[(n % 10) % 3]++;
	 length++;
	 }
	 sum = (p[1] + p[2] * 2) % 3;
	 switch (sum)
	 {
	 case 0:
		 puts("0");
		 break;
	 case 1:
		 if (p[1] && length > 1)
		 {
			 puts("1");
		 }
		 else if (p[2] >= 2 && length > 2)
		 {
			 puts("2");
		 }else{
			puts("-1");
		}
		break;
	case 2:
		if (p[2] && length > 1)
		{
			puts("1");
		}
		else if (p[1] >= 2 && length > 2)
		{
			puts("2");
		}
		else
		{
			puts("-1");
		}
		break;
	}
	return 0;
}