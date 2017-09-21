#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct nodee{int fr,to,val;}e[20005];
struct node{int to,val,nxt;}w[20005];
int h[1005],cnt=0,m,k,d[1005],vis[1005],n;
void add(int x,int y,int z){
	cnt++;w[cnt].to=y;w[cnt].nxt=h[x];w[cnt].val=z;h[x]=cnt;
}
queue<int>q;
int check(int x){
	cnt=0;
	memset(h,0,sizeof(h));
	for(int i=1;i<=2*m;i++)w[i].val=0,w[i].nxt=0,w[i].to=0;
	for(int i=1;i<=m;i++){
		if(e[i].val<x){
			add(e[i].fr,e[i].to,0);
			add(e[i].to,e[i].fr,0);
		}
		else{
			add(e[i].fr,e[i].to,1);
		    add(e[i].to,e[i].fr,1);
		}  
	}
	memset(vis,0,sizeof(0));memset(d,0x3f,sizeof(d));
	q.push(1);vis[1]=1;d[1]=0;
	while(!q.empty()){
		int fr=q.front();
		q.pop();vis[fr]=0;
		for(int i=h[fr];i;i=w[i].nxt){
			int j=w[i].to;
			if(d[j]>d[fr]+w[i].val){
				d[j]=d[fr]+w[i].val;
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
				}
			}
		}
	}
	return d[n];
}
int main(){
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	cin>>n>>m>>k;
	int l,r=0;
	for(int i=1;i<=m;i++){
		cin>>e[i].fr>>e[i].to>>e[i].val;
		r=max(r,e[i].val);
	}
	l=1;
	int tmp=r;
	while(l<=r){	
		int mid=(l+r)>>1;
		if(check(mid)<=k)r=mid-1;
		else l=mid+1;
	}
	if(tmp==r)cout<<-1;
	else cout<<l-1;
	return 0;
}
