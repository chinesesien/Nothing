#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,mmp[103][103],q[103][103],ans=-1;

void s(int x,int y,int l){
	int sum=0;
	if(l>min(n-x+1,m-y+1)){
		q[x][y]=l-1;
		return;
	}
	for(int i=x;i<x+l;i++){
		for(int j=y;j<y+l;j++){
			q[i][j]=max(0,max(q[i-1][j],max(q[i][j-1],q[i-1][j-1]))-1);
			sum+=mmp[i][j];
		}
	}
	if(sum==l*l){
		s(x,y,l+1);
	}
	else{
		q[x][y]=l-1;
		return;
	}
	return;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mmp[i][j]);
			q[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s(i,j,q[i][j]+1);
			ans=max(ans,q[i][j]);
		}
	}
	printf("%d",ans);

	return 0;
}

/*
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1

15 10 
0 0 0 0 1 0 0 0 1 0 
0 0 0 0 0 0 0 0 0 1 
0 1 1 1 1 1 0 0 0 0 
0 1 1 1 1 1 0 0 0 0 
0 0 0 0 1 0 1 1 0 0 
0 0 0 0 0 0 0 0 1 0 
0 0 0 0 1 1 1 1 1 1 
1 0 0 1 1 1 1 1 1 0 
1 0 0 0 1 1 1 1 1 0 
1 0 0 0 1 1 1 1 1 0 
1 1 0 0 1 1 1 1 1 0 
1 0 0 0 1 1 1 1 1 0 
1 0 0 0 0 1 1 1 1 0 
1 0 0 0 0 1 1 1 1 0 
0 0 1 0 0 1 1 1 1 0 
=
5
*/