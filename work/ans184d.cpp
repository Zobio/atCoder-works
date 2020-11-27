#include<stdio.h>
 
double dp[101][101][101];
double f(int a,int b,int c){
	if(dp[a][b][c]) {
		puts("dp[a][b][c] is true. Returned");
		return dp[a][b][c];
	}
	if(a==100||b==100||c==100) {
		puts("a, b or c is more than 100. Returned.");
		return 0;
	}
	double ans=0;
	ans+=(f(a+1,b,c)+1)*a/(a+b+c);
	printf("a: %.9f\n", ans);
	ans+=(f(a,b+1,c)+1)*b/(a+b+c);
	printf("b: %.9f\n", ans);
	ans+=(f(a,b,c+1)+1)*c/(a+b+c);
	printf("c: %.9f\n", ans);
	dp[a][b][c]=ans;
	return ans;
}
 
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%.9f\n",f(a,b,c));
}