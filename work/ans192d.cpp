#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long m;
bool ck(long long x)
{
	long long al=0;
	for(int i=0;i<n;i++)
	{
		if((m-(s[i]-'0'))/x<al) //右1シフト?
		{
			cout << "false " << (m-(s[i]-'0'))/x << endl;
			return false;
		}
		cout << (m - (s[i] - '0')) / x << endl;
		cout << "x " << x << " al " << al << endl;
		al=al*x+(s[i]-'0'); //n進法で左に1シフトしている！(そのあと新しいのいっこ右に入れてる)
	}
	cout << "true " << endl;
	return true;
}
int main()
{
	cin>>s>>m;
	n=s.size();
	if(n==1)
	{
		cout<<(s[0]-'0'<=m)<<endl;
		return 0;
	}
	int d=0;
	for(int i=0;i<n;i++)
	{
		d=max(d,s[i]-'0');
	}
	long long l=d+1,r=2e18;
	while(l<r)
	{
		long long md=(l+r)/2;
		cout << "md: " << md << endl;
		if(ck(md))
		{
			l=md+1;
		}
		else
		{
			r=md;
		}
	}
	cout<<l-d-1<<endl;
	return 0;
}