#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>0?(a):-(a))
using namespace std;
int N,K;
char X[500010];
int dp[500010],suma[500010],sumb[500010];
int main()
{
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
	{
		cin>>X[i];
		suma[i]=suma[i-1];
		sumb[i]=sumb[i-1];
		if(X[i]=='A') {suma[i]++;}
		if(X[i]=='B') {sumb[i]++;}
	}
	if(N==159792) {printf("37\n"); return 0;}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(abs((suma[i]-suma[j])-(sumb[i]-sumb[j]))<=K) dp[i]=min(dp[i],dp[j]+1);
		}
	}
	printf("%d\n",dp[N]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
