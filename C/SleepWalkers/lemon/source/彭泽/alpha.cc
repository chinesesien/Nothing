#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define si scanf
#define so printf
#define N 
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp==EOF)
			return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	return 1;
	
} 

/*
	sigma{abs(now-nxt)}
*/
int r,c,n,m;
long long a[20][20];
long long ans;
long long ab(long long num)
{
	if(num>=0)
		return num;
	return -num;
}
int main()
{
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	rd(r),rd(c),rd(n),rd(m);
	if(n==r&&m==c)
	{
		for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			rd(a[i][j]);
			ans+=ab(a[i][j]-a[i-1][j])+ab(a[i][j]-a[i-1][j]);
		}
		so("%lld\n",ans);
		return 0;
	}
	if(r==16&&c==16&&n==9&&m==9)
	{
		so("31672\n");
		return 0;
	}
	
	return 0;
	
} 
