#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define maxn 500050
#define ll long long 
#define inf 500050
using namespace std;
int n,m;
int f[maxn],g[maxn<<1];
int a[maxn],b[maxn],fa[maxn],fb[maxn];
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
struct nn
{
    int data,l,r;
}t[maxn<<3];
void update(int u)
{
    t[u].data=min(t[u<<1].data,t[(u<<1)|1].data);
}
void build(int u,int x,int y)
{
    t[u].l=x;
    t[u].r=y;
    t[u].data=inf;
    if(x==y)
    {
        return ;
    }
    int mid=(x+y)>>1;
    build((u<<1),x,mid);
    build((u<<1)|1,mid+1,y);
}
void change(int u,int x,int o)
{
    if(t[u].l==x&&t[u].r==x)
    {
        t[u].data=o;
        return ;
    }
    int mid=(t[u].l+t[u].r)>>1;
    if(x<=mid)change(u<<1,x,o);
    else change((u<<1)|1,x,o);
    update(u);
}
int query(int u,int x,int y)
{
    if(t[u].l==x&&t[u].r==y)
    {
        return t[u].data;
    }
    int mid=(t[u].l+t[u].r)>>1;
    if(mid>=y)
        return query(u<<1,x,y);
    else if(mid<x)
        return query((u<<1)|1,x,y);
    else 
        return min(query((u<<1),x,mid),query((u<<1)|1,mid+1,y));
}
int main()
{
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
    int x,y,z;
    char ch[10];
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",ch);
        a[i]=a[i-1]+(ch[0]=='A');
        b[i]=b[i-1]+(ch[0]=='B');
    }
    memset(fa,0x3f,sizeof(fa));
    memset(fb,0x3f,sizeof(fb));
    memset(g,0x3f,sizeof(g));
    g[500000]=f[0]=fa[0]=fb[0]=0;
    build(1,-500000,500000);
    change(1,0,0);
    for(int i=1;i<=n;i++)
    {
        x=fa[a[i]];
        y=fb[b[i]];
        z=query(1,-m-a[i]+b[i],m+b[i]-a[i]);
//        printf("%d -- %d -- %d -- %d \n",x,y,z,f[i-1]);
        f[i]=min(min(x,y),min(f[i-1],z))+1;
        fa[a[i]]=min(fa[a[i]],f[i]);
        fb[b[i]]=min(fb[b[i]],f[i]);
        if(f[i]<g[b[i]-a[i]+500000])
        {
            g[b[i]-a[i]+500000]=f[i];
            change(1,b[i]-a[i],f[i]);
        }
    }
    printf("%d\n",f[n]);
    return 0;
} 
