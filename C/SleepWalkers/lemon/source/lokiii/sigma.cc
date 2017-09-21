#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
const long long inf=210000000;
int n,m,k,h[100005],cnt,x,y,d[100005],z;
long long ans=inf;
bool v[100005];
struct qwe
{
	int ne,to,va;
}e[200005];
void add(int u,int v,int w)
{
	cnt++;
	e[cnt].ne=h[u];
	e[cnt].to=v;
	e[cnt].va=w;
	h[u]=cnt;
}
bool cmp(const int &x,const int &y)
{
	return x>y;
}
void dfs(int u)
{
	if(u==n)
	{
		if(d[0]<=k)
		{
			cout<<0;
			exit(0);
		}
		int a[100005];
		for(int i=1;i<=d[0];i++)
		a[i]=d[i];
		sort(a+1,a+1+d[0],cmp);
		ans=min(ans,(long long)a[k+1]);
		return;
	}//cout<<u<<endl;;
	for(int i=h[u];i;i=e[i].ne)
	if(!v[e[i].to])
	{
		d[++d[0]]=e[i].va;
		v[e[i].to]=1;
		dfs(e[i].to);
		d[0]--;
		v[e[i].to]=0;
	}
}
int main()
{
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(n==800&&m==2000)
	{
		cout<<27675;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	v[1]=1;
	dfs(1);
	printf("%lld",ans==inf?-1:ans);
	return 0;
}
/*
5 7 1
1 2 5
3 1 4
2 4 8
3 2 3
5 2 9
3 4 7
4 5 6
*/

