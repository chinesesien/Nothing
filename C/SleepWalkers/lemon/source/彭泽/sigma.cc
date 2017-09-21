#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define si scanf
#define so printf
#define N 1100
#define M 10100
#define INF  
#define nxt t[j]
#define nx2 t2[j]
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

struct edge
{
	int u,v;
	long long l;
	int i,j;
	edge(int uu=0,int vv=0,long long ll=0,int ii=0,int jj=0)
	{
		u=uu;
		v=vv;
		l=ll;
		i=ii,j=jj;
	}
	friend bool operator < (edge a,edge b)
	{
		return a.l<b.l;
	}
}e[M];
struct sta
{
	int p;
	int d;
	sta(int point,int distance)
	{
		p=point;
		d=distance;
	}
	friend bool operator > (sta a,sta b)
	{
		return a.d<b.d;
	}
	friend bool operator < (sta a,sta b)
	{
		return a.d>b.d;
	}
};
int n,m;
long long k;
int h[N],t[M*2],x[M*2],z[M*2],tot;
bool ex[M*2];
int add(int u,int v,long long l)
{
	tot++;
	x[tot]=h[u];
	h[u]=tot;
	t[tot]=v;
	z[tot]=l;
	return tot;
}
queue<int> q;
int h2[N],t2[M*2],x2[M*2];
int add2(int u,int v)
{
	tot++;
	x2[tot]=h2[u];
	h2[u]=tot;
	t2[tot]=v;
	return tot;
}
int ac[N];
int get(int xx)
{
	if(ac[xx]==xx)
		return xx;
	ac[xx]=get(ac[xx]);
	return ac[xx];
}
bool vis[N];
void bfs(int bg)
{
	while(!q.empty())	q.pop();
	q.push(bg);
	vis[bg]=1;
	int now;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int j=h[now];j;j=x[j])
			if(!vis[nxt]&&ex[j])
			{
				ac[nxt]=get(now);
				q.push(nxt);
				vis[nxt]=1;
			}
	}
}
int d[N];
bool ok(int mid)
{
	memset(ex,0,sizeof(ex));
	for(int i=1;i<=m;i++)
	{
		if(e[i].l>e[mid].l)
			break;
		ex[e[i].i]=1;
		ex[e[i].j]=1;
	}
	for(int i=1;i<=n;i++)
		ac[i]=i;
	memset(vis,0,sizeof(vis));
	bfs(1);
	bfs(n);
	for(int i=2;i<n;i++)//缩点 
		if(!vis[i])
			bfs(i);
	memset(h2,0,sizeof(h2));
	tot=0;
	for(int i=mid+1;i<=m;i++)//重新建图 
	{
		if(e[i].l<=e[mid].l)
			continue;
		if(get(e[i].u)!=get(e[i].v))
		{
			get(e[i].u);
			add2(get(e[i].u),get(e[i].v));
			add2(get(e[i].v),get(e[i].u));
		}
	}
	while(!q.empty())	q.pop();
	q.push(1);
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	d[1]=0;
	int mnd=40000;
	int now;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now==n)
		{
			return d[n]<=k;
		}
		for(int j=h2[now];j;j=x2[j])
			if(!vis[nx2])
			{
				vis[nx2]=1;
				d[nx2]=d[now]+1;
				q.push(nx2);
			}
	}
		
}
int main()
{
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	rd(n),rd(m),rd(k);
	int u,v;
	long long lth;
	for(int i=1;i<=m;i++)
	{
		rd(u),rd(v);
		rd(lth);
		e[i]=edge(u,v,lth,add(u,v,lth),add(v,u,lth));
	}
	while(!q.empty())	q.pop();
	q.push(1);
	vis[1]=1;
	d[1]=0;
	int now;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now==n)
		{
			if(d[n]<=k)
			{
				so("0\n");
				return 0;
			}
			break;
		}
		for(int j=h[now];j;j=x[j])
			if(!vis[nxt])
			{
				q.push(nxt);
				vis[nxt]=1;
				d[nxt]=d[now]+1;
			}
	}
	if(!vis[n])
	{
		so("-1\n");
		return 0;
	}
	sort(e+1,e+m+1);
	int l=1,r=m,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ok(mid))
			r=mid;
		else
			l=mid+1;
	}
	so("%lld\n",e[l].l);
	return 0;	
	
} 
