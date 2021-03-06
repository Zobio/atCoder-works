#include<iostream>
#include<vector>
using namespace std;
int N,M;
vector<int>id[1500001];
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;
		id[A].push_back(i);
	}
	for(int i=0;;i++)
	{
		int pre=0;
		bool fn=false;
		for(int j:id[i])
		{
			if(j-pre>=M)fn=true;
			pre=j+1;
		}
		if(N-pre>=M)fn=true;
		if(fn)
		{
			cout<<i<<endl;
			return 0;
		}
	}
}
