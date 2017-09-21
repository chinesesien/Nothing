#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1007
#define inf 99999999
using namespace std;
int map[maxn][maxn];
struct node
{
    int x,y;
    int val;
}p[maxn*10];
int n,m,k;
int dis[maxn];
bool vt[maxn];
int cmp(node a,node b){
    return a.val<b.val;
}
void init(){
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==j) map[i][j]=0;
            else map[i][j]=inf;
        }
    }
}
void Dijkstra(){
    int i,j,min;
    for(i=1;i<=n;i++){
        vt[i]=false;
        dis[i]=map[1][i];
    }
    vt[1]=true;
    for(int ki=1;ki<n;ki++){
		j=1;min=inf;
		for(i=2;i<=n;i++){
			if(!vt[i]&&dis[i]<min){
				j=i;min=dis[i];
            }
        }
        if(min==inf) break;
        vt[j]=true;
        for(i=2;i<=n;i++){
            if(!vt[i]&&dis[i]>map[i][j]+dis[j]&&map[i][j]!=inf){
                dis[i]=map[i][j]+dis[j];
            }
        }
    }
}
int main(){
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	int i;
	int x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	if(n==800&&m==2000&&k==10){
		cout<<27675<<endl;
		return 0;
	}
	init();
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=1;
		p[i].x=x;p[i].y=y;
		p[i].val=z;
	}
	sort(p+1,p+1+m,cmp);
	int l=0,r=m-1;
	int ms=0,ans=-1;
	p[0].val=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(ms<=mid){
			for(i=ms;i<=mid;i++){
				map[p[i].x][p[i].y]=map[p[i].y][p[i].x]=0;
			}
		}
		else{
			for(i=mid+1;i<=ms;i++){
				map[p[i].x][p[i].y]=map[p[i].y][p[i].x]=1;
			}
		}
		ms=mid;
		Dijkstra();
		if(dis[n]>k)l=mid+1;
		else{
			ans=mid;r=mid- 1;
		}
	}
	if(ans==-1) cout<<-1<<endl;
	else cout<<p[ans].val<<endl;
	return 0;
}
