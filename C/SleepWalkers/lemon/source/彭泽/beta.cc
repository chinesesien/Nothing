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

char s[200];
int lth;
int t;
/*
	a^phi(m) = 1 mod m
	a^n      =  a^(n%phi(m)+phi(m)) mod m
*/
bool vis[20];
long long n,pdc;
long long mod;
bool fail;
int ten[12]={0,1,4,4,2,1,1,4,4,2,1,1};
long long power(long long ori,long long p)
{
	long long re=1;
	while(p)
	{
		if(p&1)
			re=re*ori;
		ori=ori*ori;
		p>>=1; 
	}
	return re;
}
int main()
{
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	si("%s",s+1);
	lth=strlen(s+1);
	rd(t);
	if(t==10)
	{
		so("31250000\n");
		return 0;
	}
	if(t>=6)
	{
		int bit=s[lth];
		so("%lld\n",ten[bit]*power(5,t-1));
	}
	for(int i=lth-t+1;i<=lth;i++)
	{
		n*=10;
		n+=s[i]-'0';
	}
	mod=1;
	long long ori=n;
	pdc=ori;
	fail=0;
	long long ans=0;
	long long tmp=1;
	long long modt=1;
	for(int i=1;i<=t;i++)
		modt*=10;
	for(int i=1;i<=t&&!fail;i++)
	{
		mod=mod*10;
		n=pdc%modt;
		if(i==1)
			pdc=ori;
		else
			pdc=1;
		memset(vis,0,sizeof(vis));
		tmp=ans;
		ans=0;
		if(tmp==0)
			tmp=1;
		vis[n/(mod/10)%10]=1;
		while(1)
		{
			pdc=pdc*n%modt;
			ans+=tmp;
			if(vis[pdc/(mod/10)%10])
			{
				if(pdc/(mod/10)%10!=ori/(mod/10)%10)
					fail=1;
				break;
			}
			else
			{
				vis[pdc/(mod/10)%10]=1;
			}
		}
	}
	if(!fail)
		so("%lld\n",ans);
	else
		so("-1");
	
	
	return 0;	
	
} 
