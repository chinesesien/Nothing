#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int r,c,n,m,mmp[20][20]={{0},{0}},mmmp[20][20]={{0},{0}},ans=1e9+7,xh[20]={0},xl[20]={0};
bool yxh[20]={0},yxl[20]={0};

void dfs(int x,int y){
	if(x>0){
		for(int i=1;i<=r;i++){
			if(yxh[i]==0&&i>xh[n-x]){
				xh[n-x+1]=i;
				yxh[i]=1;
				dfs(x-1,y);
				yxh[i]=0;
			}
			else continue;
			xh[n-x+1]=0;
		}
	}
	else if(y>0){
		for(int i=1;i<=c;i++){
			if(yxl[i]==0&&i>xl[m-y]){
				xl[m-y+1]=i;
				yxl[i]=1;
				dfs(x,y-1);
				yxl[i]=0;
			}
			else continue;
			xl[m-y+1]=0;
		}
	}
	else{
		int tans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				mmmp[i][j]=mmp[xh[i]][xl[j]];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i-1>=1) tans+=abs(mmmp[i][j]-mmmp[i-1][j]);
				if(tans>=ans) return;
				if(j-1>=1) tans+=abs(mmmp[i][j]-mmmp[i][j-1]);
				if(tans>=ans) return;
				if(i+1<=n) tans+=abs(mmmp[i][j]-mmmp[i+1][j]);
				if(tans>=ans) return;
				if(j+1<=m) tans+=abs(mmmp[i][j]-mmmp[i][j+1]);
				if(tans>=ans) return;
			}
		}
		if(tans>=ans) return;
		ans=tans;
	}
	return;
}

int main(){
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	scanf("%d%d%d%d",&r,&c,&n,&m);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&mmp[i][j]);
	int rc=max(r,c);
	dfs(n,m);
	printf("%d",ans/2);
	return 0;
}

/*
5 5 2 3
9 3 3 3 9
9 4 8 7 4
1 7 4 6 6
6 8 5 6 9
7 4 5 6 1

*/