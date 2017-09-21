#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

#define maxn 1500
#define maxm 25000
const int INF=0x3f3f3f3f;

struct N {
    int u,v,w;
    N(int a=0,int b=0,int c=0){u=a,v=b,w=c;}
    friend bool operator < (N a,N b){
	return a.w<b.w;
    }
    void ass(int a,int b,int c){
	u=a,v=b,w=c;
    }
}edge[maxm];

int head[maxn],nxt[maxm],point[maxm],w[maxm];
int vis[maxn],d[maxn],f[maxn],fa[maxn],inq[maxn];
int tot,n,m,mk;

void add(int x,int y,int z){
    point[++tot]=y;edge[tot].ass(x,y,z);
    w[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot;
}

int readin(){
    int x=0,s=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*s;
}

int getf(int x){
    return x==fa[x]?x:(fa[x]=getf(fa[x]));
}

queue<int>q,q1;
bool kru(int lmt){
    for(int i=1;i<=n;i++)fa[i]=i;
    memset(vis,0,sizeof(vis));
    memset(inq,0,sizeof(inq));
    memset(d,INF,sizeof(d));
    for(int i=1;i<=tot;i++){
	if(edge[i].w<=lmt){
	    int x=getf(edge[i].u),y=getf(edge[i].v);
	    if(x!=y)fa[x]=y;
	}
    }
    d[getf(1)]=0;
    q.push(getf(1));
    while(!q.empty()){
	int x=q.front(),y,z;q.pop();y=getf(x);
	if(!vis[x])q1.push(x);
	while(!q1.empty()){
	    int h=q1.front();q1.pop();
	    for(int i=head[h];i;i=nxt[i]){
		z=getf(point[i]);
		if(vis[point[i]])continue;
		if(z==y){
		    q1.push(point[i]);vis[point[i]]=1;
		}
		else if(!inq[z]){
		    q.push(z);
		    inq[z]=1;
		    d[z]=d[x]+1;
		}
	    }
	}
    }
    if(d[getf(n)]<=mk)return true;
    //for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<endl;
    return false;
}

int main(){
    freopen("sigma.in","r",stdin);
    freopen("sigma.out","w",stdout);
    int maxl=0;
    n=readin();
    m=readin();
    mk=readin();
    for(int i=1,x,y,z;i<=m;i++){
	x=readin();y=readin();z=readin();
	maxl=max(maxl,z);
	add(x,y,z);
	add(y,x,z);
    }
    memset(f,INF,sizeof(f));
    //for(int i=1;i<=tot;i++)cout<<edge[i].u<<"->"<<edge[i].v<<endl;
    sort(edge+1,edge+tot+1);
    if(!kru(maxl*2)){puts("-1");return 0;}
    //for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
    int l=0,r=maxl*2,mid;
    while(l<r){
	mid=(l+r)>>1;
	if(kru(mid))r=mid;
	else if(l==mid)break;
	else l=mid;
    }
    cout<<r<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
