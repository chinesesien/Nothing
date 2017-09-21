#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int N,M,K,tot=0,tt=0,can;
int head[1010],nxt[20200],point[20020],edge[20020];
int bl[1010]; bool vis[1010];
int nhead[1010],nnxt[20200],npoint[20020],ntot=0;
bool nvis[1010];
struct pt
{
	int shuyu,nd;	
};
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9')   {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
void add(int a,int b,int c)
{
	++tot;
	nxt[tot]=head[a];
	point[tot]=b;
	edge[tot]=c;
	head[a]=tot;
}
void nadd(int a,int b)
{
	++ntot;
	nnxt[ntot]=nhead[a];
	npoint[ntot]=b;
	nhead[a]=ntot;
}
void dfs1(int now)
{
	int l;
	vis[now]=true;
	bl[now]=tt;
	for(int i=head[now];i;i=nxt[i])
	{
		l=point[i];
		if(edge[i]<=can&&!vis[l])
		{
			dfs1(l);
		}
	}
}
bool ty()
{
	if(bl[1]==bl[N]) return true;
	queue<pt> q;
	pt x;
	x.shuyu=bl[N];
	nvis[bl[N]]=true; 
	x.nd=0;
	q.push(x);
	while(!q.empty())
	{
		pt r=q.front();
		q.pop();
		if(r.nd==K) break;
		int l,k=r.shuyu;
		for(int i=nhead[k];i;i=nnxt[i])
		{
			l=npoint[i];
			if(!nvis[l]) 
			{
				if(l==bl[1]) return true;
				nvis[l]=true;
				pt o;
				o.shuyu=l;
				o.nd=r.nd+1;
				q.push(o);
			}
		}
	}
	return false;
}
bool ok(int ha)
{
	ntot=0;
	tt=0;
	can=ha;
	memset(vis,false,sizeof(vis));
	memset(nvis,false,sizeof(nvis));
	memset(nhead,0,sizeof(nhead));
	for(int i=1;i<=N;i++)
	{
		if(!vis[i]) 
		{
			++tt;
			dfs1(i);
		}
	}
	int l;
	for(int i=1;i<=N;i++)
	{
		for(int j=head[i];j;j=nxt[j])
		{
			l=point[j];
			if(bl[i]!=bl[l])
			{
				nadd(bl[i],bl[l]);	
			}	
		}
	}
	return ty();
}
int main()
{
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	N=read(); M=read(); K=read();
	int a,b,c;
	for(int i=1;i<=M;i++)
	{
		a=read(); b=read(); c=read();
		add(a,b,c);
		add(b,a,c);
	}
	int lf=0,rg=1000000;
	int mid;
	while(lf+1<rg)
	{
		mid=(lf+rg)>>1;
		if(ok(mid)) rg=mid;
		else lf=mid;
	}
	if(ok(lf)) printf("%d\n",lf);
	else if(ok(rg)) printf("%d\n",rg);
	else printf("-1\n");
	fclose(stdin);
	fclose(stdout);
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
