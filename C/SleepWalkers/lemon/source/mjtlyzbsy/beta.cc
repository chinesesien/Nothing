#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxm=100010;
int INF=100010;
bool vis[maxm];
int main(){
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	int n,ans,t;
	scanf("%d%d",&n,&t);
	int x=10;
	for(int i=1;i<t;i++){
		x=x*10;
	}
	int res=0;
	memset(vis,false,sizeof(vis));
	ans=n;
	while(INF--){
		ans=(ans*n)%x;
		if(vis[ans]){
			printf("%d\n",res);
			return 0;
		}
		res++;
		vis[ans]=true;
	}
	printf("-1\n");
	return 0;
} 
