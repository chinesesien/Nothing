#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#define pa pair<int,int>
#define maxn 50010
#define ll long long 
#define inf 2147483647
using namespace std;
int n,m,tmp=1,cnt=27;
int ver[maxn],nxt[maxn],head[maxn],we[maxn];
int vis[maxn],dis[maxn];
priority_queue<pa,vector<pa>,greater<pa> >q; 
string s;
struct point
{
	double v;
}a[maxn];
double ans[maxn];
void add(int x,int y,int z)
{
	nxt[++tmp]=head[x];
	ver[tmp]=y;
	we[tmp]=z;
	head[x]=tmp;
}
void dijkstra(int x)
{
    int y,z;
	for(int i=1;i<=cnt;i++)dis[i]=inf;
	memset(vis,0,sizeof(vis));
    dis[x]=0;
    q.push(make_pair(0,x));
    while(!q.empty())
    {
        int k=q.top().second;
        q.pop();
        if(vis[k])continue;
        vis[k]=1;
        for(int i=head[k];i;i=nxt[i])
        {
            y=ver[i];
            z=we[i];
            if(dis[k]+z<dis[y])
            {
                dis[y]=dis[k]+z;
                q.push(make_pair(dis[y],y));
            }
        }
    }
}
void init()
{
	char ch;
	scanf("%d",&n);
	getline(cin,s);
    cnt=n;
    for(int i=1;i<=n;i++)
    	a[i].v=0;
    for(int i=1;i<=n;i++)
    {
		int step=0;
		getline(cin,s);
    	m=s.length();
		memset(dis,0,sizeof(dis));
    	int f=1;
    	int x=0,y;
    	for(int j=0;j<m;j++)
    	{
    		if(s[j]=='-')f=-1;
    		if(s[j]>='0'&&s[j]<='9')
    		{
    			int x=s[j]-'0';
    			while(s[j+1]>='0'&&s[j+1]<='9')
    			{
    				j++;
    				x=x*10+s[j]-'0';
				}
				a[++cnt].v=x*f;
				x=0;
				f=1;
				add(i,cnt,step);
			}
    		else if(s[j]>='a'&&s[j]<='z'&&s[j]!='a'+i-1)
    		{
    			y=s[j]-'a'+1;
    			if(step<dis[y]||!dis[y])
    			{
    				add(i,y,step);
    				dis[y]=step;
				}	
			}
			if(s[j]=='[')
			{
				step++;
			}
			if(s[j]==']')
			{
				step--;
			}
		}
	}
}
int main()
{
	int x;
	init();
    for(int i=1;i<=n;i++)
    {
    	dijkstra(i);
    	ans[i]=0.0;
    	for(int j=1;j<=cnt;j++)
    	{
    		if(dis[j]<inf)
    		{
    			ans[i]+=a[j].v*pow(0.5,dis[j]);
			}
		}
	}
    for(int i=1;i<=n;i++)
    {
    	if(ans[i]>=0.0000001)
    		printf("%c = %.3lf\n",'a'+i-1,ans[i]);
    	else printf("Unknown\n");
	}
    return 0; 
} 
