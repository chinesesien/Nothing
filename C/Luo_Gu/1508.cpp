#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int m,n,mmp[1003][1003];

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&mmp[i][j]);
			if(i>=2) mmp[i][j]+=max(mmp[i-1][j-1],max(mmp[i-1][j],mmp[i-1][j+1]));
		}
	printf("%d",max(mmp[m][n/2+1],max(mmp[m][n/2],mmp[m][n/2+2])));

	return 0;
}

/*
6 7
16 4  3 12  6  0  3
4 -5  6  7  0  0  2
6  0 -1 -2  3  6  8
5  3  4  0  0 -2  7
-1 7  4  0  7 -5  6
0 -1  3  4 12  4  2

*/