#include<bits/stdc++.h>
#define int long long
using namespace std;
double f[102][102][102],ans;
int a,b,c,cnt;
signed main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i=99;i>=a;i--) {
		for(int j=99;j>=b;j--) {
			for(int k=99;k>=c;k--) {
				f[i][j][k]=1 + (f[i][j][k+1] * k + f[i][j+1][k] * j + f[i+1][j][k] * i)/(i + j + k);
				printf("f[%lld][%lld][%lld]: = %f\n", i, j, k, f[i][j][k]);
			}
		}
	}
	printf("%.9lf",f[a][b][c]);
    return 0;
}