#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int r,c,n,m,a[20][20],p[70000],q[70000],h[20][20][20],l[20][20][20],ans=210000000,vh[20],vl[20];
void dp(int x,int y)
{
 	//memset(vh,0,sizeof(vh));
	//memset(vl,0,sizeof(vl));
	vh[0]=0;vl[0]=0;
	int re=0;
	for(int i=0;i<c;i++)
	if(x&(1<<i))
	vh[++vh[0]]=i+1;//cout<<vh[0]<<" ";
	for(int i=0;i<r;i++)
	if(y&(1<<i))
	vl[++vl[0]]=i+1;//cout<<vl[0]<<endl;
	for(int i=1;i<=vh[0];i++)
	for(int j=2;j<=vl[0];j++)
	{
		re+=l[vh[i]][vl[j-1]][vl[j]];
		if(re>=ans)
		return;
	}
	for(int i=1;i<=vl[0];i++)
	for(int j=2;j<=vh[0];j++)
	{
		re+=h[vl[i]][vh[j-1]][vh[j]];
		if(re>=ans)
		return;
	}
	ans=min(ans,re);
	//cout<<x<<" "<<y<<" "<<ans<<endl;
}
int main()
{
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	scanf("%d%d%d%d",&r,&c,&n,&m);
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	scanf("%d",&a[i][j]);
	for(int k=1;k<=r;k++)
	for(int i=1;i<=c;i++)
	for(int j=1;j<=c;j++)
	l[k][i][j]=abs(a[i][k]-a[j][k]);
	for(int k=1;k<=c;k++)
	for(int i=1;i<=r;i++)
	for(int j=1;j<=r;j++)
	h[k][i][j]=abs(a[k][i]-a[k][j]);
	for(int i=0;i<(1<<c);i++)//hang
	{
		int k=i,sum=0;
		while(k)
		{
			sum+=(k&1);
			k>>=1;
		}
		if(sum==m)
		p[++p[0]]=i;
	}
	for(int i=0;i<(1<<r);i++)//lie
	{
		int k=i,sum=0;
		while(k)
		{
			sum+=(k&1);
			k>>=1;
		}
		if(sum==n)
		q[++q[0]]=i;
	}
	for(int i=1;i<=p[0];i++)
	for(int j=1;j<=q[0];j++)
	dp(p[i],q[j]);
	printf("%d",ans);
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
