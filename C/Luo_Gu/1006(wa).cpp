#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,mmp[53][53],dp[53][53][53][53];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) mmp[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mmp[i][j]);
		}
	}
	for(int i=m;i>=1;--i)
		for(int j=n;j>=1;--j)
			for(int k=m;k>=1;--k)
				for(int z=n;z>=1;--z){
					if(i-1!=k-1||j!=z) dp[i-1][j][k-1][z]=max(dp[i-1][j][k-1][z],dp[i][j][k][z]+mmp[i-1][j]+mmp[k-1][z]);
					if(i-1!=k||j!=z-1) dp[i-1][j][k][z-1]=max(dp[i-1][j][k][z-1],dp[i][j][k][z]+mmp[i-1][j]+mmp[k][z-1]);
					if(i!=k-1||j-1!=z) dp[i][j-1][k-1][z]=max(dp[i][j-1][k-1][z],dp[i][j][k][z]+mmp[i][j-1]+mmp[k-1][z]);
					if(i!=k||j-1!=z-1) dp[i][j-1][k][z-1]=max(dp[i][j-1][k][z-1],dp[i][j][k][z]+mmp[i][j-1]+mmp[k][z-1]);
				}
	printf("%d",dp[2][1][1][2]);
	return 0;
}

/*
3 3
0 3 9
2 8 5
5 7 0

8 6
0  94 11 25 24 51 
15 13 39 67 97 19 
76 12 33 99 18 92 
35 74  0 95 71 39 
33 39 32 37 45 57 
71 95  5 71 24 86 
8  51 54 74 24 75 
70 33 63 29 99  0 
=
1382

*/