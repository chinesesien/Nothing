#include<stdio.h>
#include<iostream> 
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdlib>
using namespace std;
typedef long long ll;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct date{
	int to,next,d;
}e[10100];
int head[1100],cnt;
void insert(int u,int v,int d){
	e[cnt].to=v;
	e[cnt].d=d;
	e[cnt].next=head[u];
	head[u]=cnt;
	cnt++;
}
int from[10100];
int to[10100];
int v[10100];
const int maxq=100000;
int n,m,k;
bool inq[1100];
int dis[1100];
int q[100100];
int spfa(){
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	int s=0,w=1;
	q[0]=1;
	inq[1]=1;
	dis[1]=0;
	while(s<w){
		int u=q[s++];
		if(s==maxq)s=0;
		for(int i=head[u];~i;i=e[i].next){
			int to=e[i].to;
			if(dis[to]>dis[u]+e[i].d){
				dis[to]=dis[u]+e[i].d;
				if(!inq[to]){
					inq[to]=1;
					q[w++]=to;
					if(w==maxq)w=0;
				}
			}
		}
	}
	return dis[n];
}
void init(int x){
	memset(head,-1,sizeof(head));
	cnt=0;
	for(int i=1;i<=m;i++){
		if(v[i]<=x){
			insert(from[i],to[i],0);
			insert(to[i],from[i],0);
		}
		else{
			insert(from[i],to[i],1);
			insert(to[i],from[i],1);
		}
	}
}
int main(){
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout); 
	n=read();
	m=read();
	k=read();
	int l=0,r=0;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&from[i],&to[i],&v[i]);
	for(int i=1;i<=m;i++)r=max(r,v[i]);
	while(l<r){
		int mid=(l+r)>>1;
		init(mid);
		int ret=spfa();
		if(ret<=k){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d",r);
	return 0;
}
