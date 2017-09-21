#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int R,C,N,M,ans=999999999;
int mp[20][20],np[20][20],dp[20][20];
int cun[20],cos[20];
int abs(int a)
{
	if(a<0) a=-a;
	return a; 
}
bool ck(int k)
{
	int ans=0;
	while(k)
	{
		if(k&1) ans++;
		k=k>>1;
	}
	if(ans==M) return true;
	else return false;
}
void gao(int k)
{
	int tt=1,cal=0;
	while(k)
	{
		if(k&1) cun[++cal]=tt;
		k=k>>1;
		tt++;
	}
}
void pr()
{
	memset(dp,0x3f,sizeof(dp));
	memset(cos,0,sizeof(cos));
	memset(np,0,sizeof(np));
	dp[0][0]=0;
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<M;j++)
		{
			cos[i]+=abs(mp[i][cun[j]]-mp[i][cun[j+1]]);	
		}
	}
	for(int i=1;i<=R;i++)
	{
		for(int j=i+1;j<=R;j++)
		{
			for(int l=1;l<=M;l++)
			{
				np[i][j]+=abs(mp[i][cun[l]]-mp[j][cun[l]]);
			}
			np[j][i]=np[i][j];
		}
	}
}
int main()
{
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	scanf("%d%d%d%d",&R,&C,&N,&M);
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			scanf("%d",&mp[i][j]);			
		}
	}
	int a=(1<<C)-1;
	for(int i=1;i<=a;i++)
	{
		if(ck(i))
		{
			gao(i);
			pr();
			for(int j=1;j<=N;j++) //个数 
			{
				for(int k=j;k<=R;k++) //当前行 
				{
					for(int l=j-1;l<k;l++) //从那转移 
					{
						dp[j][k]=min(dp[j][k],dp[j-1][l]+cos[k]+np[l][k]);
					}
				}
			}
			for(int k=1;k<=R;k++)
			{
				ans=min(ans,dp[N][k]);
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5 2 3
9 3 3 3 9
9 4 8 7 4 
1 7 4 6 6
6 8 5 6 9
7 4 5 6 1
*/
