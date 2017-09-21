#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int had[1002],nxt[20004],point[20004],val[20004];
int tot;
struct line{
	int frm,to;
	int val;
	int num;
}li[10004];
bool cmp(line a,line b)
{
	return a.val<b.val;
}
inline void add(int x,int y,int v)
{
	tot++;
	point[tot]=y;
	val[tot]=v;
	nxt[tot]=had[x];
	had[x]=tot;
}
int n,m,k;
int vis[1003];
queue<int>q;
int fa[1003];
int getfa(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=getfa(fa[x]);
}
struct mine{
	int num;
	int dis;
};
priority_queue<mine> qq;
bool operator < (mine a,mine b)  
{  
	if(a.dis == b.dis) 
		return a.num>b.num;  
	return a.dis>b.dis;              //ÏÈ³öÐ¡   
}  
int len[1003];
int main()
{
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		cin>>li[i].frm>>li[i].to>>li[i].val;
		add(li[i].frm,li[i].to,li[i].val);
		add(li[i].to,li[i].frm,li[i].val);
	}
	vis[1]=1;
	q.push(1);
	while((!q.empty())&&vis[n]==0)
	{
		int t=q.front();
		q.pop();
		for(int i=had[t];i;i=nxt[i])
		{
			int to=point[i];
			if(!vis[to])
			{
				vis[to]=vis[t]+1;
				q.push(to); 
			}
		}
	}
	if(vis[n]==0)
	{
		cout<<-1;
		return 0;
	}
	if(vis[n]-1<=k)
	{
		cout<<0;
		return 0;
	}
	sort(li+1,li+1+m,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	memset(vis,0,sizeof(vis));
	tot=0;
	memset(had,0,sizeof(had));
	memset(point,0,sizeof(point));
	memset(nxt,0,sizeof(nxt));
	memset(val,0,sizeof(val));
	for(int i=1;i<=m;i++)
	{
		int x=getfa(li[i].frm);
		int y=getfa(li[i].to);
		if(fa[x]!=fa[y])
		{
			fa[x]=fa[y];
			add(li[i].frm,li[i].to,li[i].val);
			add(li[i].to,li[i].frm,li[i].val);
		}
	}
	memset(len,0x3f3f3f,sizeof(len));
	len[1]=0;
	mine p;
	p.num=1;
	p.dis=0;
	qq.push(p);
	while(!qq.empty())
	{
		mine t=qq.top();
		qq.pop();
		for(int i=had[t.num];i;i=nxt[i])
		{
			if(len[point[i]]>max(len[t.num],val[i]))
			{
				len[point[i]]=max(len[t.num],val[i]);
				mine p;
				p.num=point[i];
				p.dis=len[p.num];
				qq.push(p);
			}
		}
	}
	cout<<len[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
