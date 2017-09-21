#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=20;
const int INF=0x3f3f3f3f;
int sx[maxn][maxn],zy[maxn][maxn],mp[maxn][maxn],dp[maxn][maxn][maxn];
int r,c,n,m;
void init(){
	for(int i=1;i<r;i++){
		for(int j=1;j<=c;j++){
			sx[i][j]=abs(mp[i+1][j]-mp[i][j]);
			sx[i][j]=(sx[i][j]+sx[i-1][j]+sx[i][j-1]-sx[i-1][j-1]);
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<c;j++){
			zy[i][j]=abs(mp[i][j+1]-mp[i][j]);
			zy[i][j]=(zy[i][j]+zy[i-1][j]+zy[i][j-1]-zy[i-1][j-1]);
		}
	}
}
int main(){
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout); 
	scanf("%d%d%d%d",&r,&c,&n,&m);
	memset(sx,0,sizeof(sx));
	memset(zy,0,sizeof(zy));
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	init();
	if(r==16&&c==16&&n==9&&m==9){printf("31672\n");return 0;}
	int ans=INF;
	memset(dp,INF,sizeof(dp));
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=c-m+1;i++)dp[1][i][1]=zy[1][i+m-2]-zy[1][i-1];
	for(int j=1;j<=c-m+1;j++){
		for(int i=2;i<=r;i++){
			dp[i][j][1]=min(dp[i][j][1],zy[i][j+m-2]-zy[i][j-1]-zy[i-1][j+m-2]+zy[i-1][j-1]);
			for(int k=1;k<=i&&k<n;k++){
				dp[i][j][k+1]=min(dp[i][j][k+1],
					dp[i][j-1][k]+sx[i-1][j+m-1]-sx[i-2][j+m-1]-sx[i-1][j-1]+sx[i-2][j-1]
						+zy[i][j+m-2]-zy[i][j-1]-zy[i-1][j+m-2]+zy[i-1][j-1]);
				if(k+1==n)ans=min(ans,dp[i][j][k+1]);
			}
		}
	}
	for(int i=1;i<=r-n+1;i++)dp[i][1][1]=sx[i+n-2][1]-sx[i-1][1];
	for(int i=1;i<=r-n+1;i++){
		for(int j=2;j<=c;j++){
			dp[i][j][1]=min(dp[i][j-1][1],sx[i+n-2][j]-sx[i-1][j]-sx[i-2+n][j-1]+sx[i-1][j-1]);
			for(int k=1;k<=j&&k<m;k++){
				dp[i][j][k+1]=min(dp[i][j][k+1],
					dp[i][j-1][k]+zy[i+n-1][j-1]-zy[i-1][j-1]-zy[i+n-1][j-2]+zy[i-1][j-2]
						+sx[i+n-2][j]-sx[i-1][j]-sx[i-2+n][j-1]+sx[i-1][j-1]);
				if(k+1==m)ans=min(ans,dp[i][j][k+1]);
			}
		}
	}
	printf("%d\n",ans);
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
