#include <iostream>
using namespace std;
long L, R, ans = 2020;
main()
{
	cin >> L >> R;
	for (long l = L; l < L + 2020; l++)
		for (long r = R; r > R - 2020; r--)
		{
			if (l < r)
				ans = min(ans, l % 2019 * r % 2019);
		}
	cout << ans << endl;
}
