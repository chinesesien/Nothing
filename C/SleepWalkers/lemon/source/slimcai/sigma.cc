#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define maxn 200010
#define ll long long 
#define inf 2147483647
using namespace std;
int n,m,k,tmp=1,ans=inf;
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int ver[maxn],nxt[maxn],head[maxn],we[maxn];
int dis[1010],vis[1010];
void add(int x,int y,int z)
{
    nxt[++tmp]=head[x];
    ver[tmp]=y;
    we[tmp]=z;
    head[x]=tmp;
}
void spfa(int mid)
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(dis,63,sizeof(dis));
    vis[1]=1;
    dis[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        int y,z;
        for(int i=head[u];i;i=nxt[i])
        {
            y=ver[i];
            z=we[i]>mid?1:0;
            if(dis[y]>dis[u]+z)
            {
                dis[y]=dis[u]+z;
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        } 
    }
}
void erfen()
{
    int l=0,r=1000000;
	while(l<=r)
    {
        int mid=(l+r)>>1;
        spfa(mid);
        if(dis[n]<=k)
        {
            r=mid-1;
            ans=min(ans,mid);
        }
        else
        {
            l=mid+1;
        }
        
    }
}
int main()
{
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
    int x,y,z;
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++)
    {
        x=read();
        y=read();
        z=read();
        add(x,y,z);
        add(y,x,z);
    }
    erfen();
    if(ans==inf)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ans);
    return 0; 
} 
