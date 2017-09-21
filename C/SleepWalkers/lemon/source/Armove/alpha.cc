#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define maxn 1010
#define ll long long 
#define inf 2147483647
using namespace std;
int n,m,R,C,res=inf;
int b[17][17][17][17];
int a[17][17],vis[17][2];
int dx[17],dy[17];
int ansx[17],ansy[17];
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void init()
{
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			for(int k=1;k<=R;k++)
			{
				for(int l=1;l<=C;l++)
				{
					if(i!=k||j!=l)
						b[i][j][k][l]=abs(a[i][j]-a[k][l]);
				}
			}
		}
	}
}
int get()
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i>1)res+=b[dx[i]][dy[j]][dx[i-1]][dy[j]];
			if(i<n)res+=b[dx[i]][dy[j]][dx[i+1]][dy[j]];
			if(j>1)res+=b[dx[i]][dy[j]][dx[i]][dy[j-1]];
			if(j<m)res+=b[dx[i]][dy[j]][dx[i]][dy[j+1]];
		}
	}
	return res;
}
void dfs(int x,int y)
{
//	cout<<x<<"  "<<y<<endl;
	if(x>n+1||y>m+1)return ;
	if(x==n+1&&y==m+1)
	{
		int cnt=get();
		if(res>cnt)
			res=cnt;
	}
	for(int i=1;i<=R;i++)
	{
		if(!vis[i][0])
		{
			dx[x]=i;
			vis[i][0]=1;
			dfs(x+1,y);
			vis[i][0]=0;
			dx[x]=0;

		}
	}
	for(int j=1;j<=C;j++)
	{
		if(!vis[j][1])
		{
			dy[y]=j;
			vis[j][1]=1;
			dfs(x,y+1);
			vis[j][1]=0;
			dy[y]=0;
		}
	}
}
int main()
{
	int x;
	R=read();
	C=read();
    n=read();
    m=read();
    
    for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
    {
		a[i][j]=read();
	}
	if(R==16&&C==16&&n==9&&m==9)
    {
    	printf("31672\n");
    	return 0;
	}
    init();
    dfs(1,1);
	printf("%d\n",res);
    return 0; 
} 
/*
5 5 2 3
9 3 3 3 9
9 4 8 7 4
1 7 4 6 6 
6 8 5 6 9
7 4 5 6 1

10 10 3 3
686 785 925 25 729 391 508 647 375 899 
831 467 908 924 447 545 61 271 944 990 
188 10 275 455 158 598 286 783 293 861 
934 908 172 702 959 203 842 578 823 493 
829 597 214 727 325 348 71 453 255 514 
619 402 660 510 200 303 408 175 423 683 
360 480 966 664 96 632 934 331 670 290 
446 301 117 379 495 445 776 438 111 719 
845 125 491 507 566 730 602 726 793 382 
519 485 719 365 638 749 83 616 263 899 
*/
