#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=10010;
struct edge{
	int to,cost;
};
int V;
struct P{
	int jia,yi,bing;
};
vector <edge> G[maxn];
int d[maxn][maxn],n,m,k,ans;
struct cmp{
	bool operator() (const P &A,const P &B){
		return A.bing<B.bing;
		if(A.bing==B.bing)return A.jia>B.jia;
	}
};
inline void SPFA(int s){
    priority_queue<P,vector<P>,cmp >que;
    d[s][0]=0;
    que.push((P){0,s,0}); 
    while(!que.empty()){
        P p=que.top();que.pop();
        int w=p.jia,v=p.yi,c=p.bing;
		if(d[v][c]<w)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i]; 
            if(d[e.to][c]>w+e.cost){
                d[e.to][c]=w+e.cost;
                que.push((P){d[e.to][c],e.to,});
            }
		G[x].push_back((edge){y,z});
            if(d[e.to][c+1]>w&&c+1<=k){
            	d[e.to][c+1]=w;
            	que.push((P){d[e.to][c+1],e.to,c+1});
			}
        }
    }
}
int main(){
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	int x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	if(n<k){printf("0\n");return 0;}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		G[y].push_back((edge){x,z}); 
	}
	memset(d,INF,sizeof(d));
	SPFA(1);
	ans=INF;
	for(int i=0;i<=k;i++){
		ans=min(ans,d[n][i]);
	}
	if(ans==INF)printf("-1\n");
	else printf("%d\n",ans-1);
	return 0;
} 
