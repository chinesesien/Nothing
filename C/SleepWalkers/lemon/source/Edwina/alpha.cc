#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int map[17][17],R,C,N,M,ans=inf;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='_') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int lng[17],f[17][17];
void solve()
{
	int xy1[17],xy2[17][17];
    memset(xy2,0,sizeof(xy2));
    for(int i=1; i<=C; i++)
        for(int j=1; j<i; j++)
            for(int k=1; k<=N; k++)
                xy2[j][i]+=abs(map[lng[k]][j]-map[lng[k]][i]);
	memset(xy1,0,sizeof(xy1));
    for(int i=1; i<=C; i++)
        for(int j=1; j<N; j++)
            xy1[i]+=abs(map[lng[j+1]][i]-map[lng[j]][i]);
	memset(f,inf,sizeof(f));
    for(int i=1; i<=R; i++)
		f[i][0]=0,f[i][1]=xy1[i];
    for(int i=1; i<=M; i++)
    {
        for(int j=i; j<=C; j++)
        {
            for(int k=i-1; k<j; k++)
            {
                f[j][i]=min(f[k][i-1]+xy2[k][j]+xy1[j],f[j][i]);
            }
        }
    }
    for(int i=M; i<=C; i++)
        ans=min(ans,f[i][M]);
}

void dfs(int noww,int x)
{
	if(N-noww>x)
        return;
    if(noww==N)
    {
        solve();
        return;
    }
    for(int i=x; i>=1; i--)
    {
        lng[noww+1]=i;
        dfs(noww+1,i-1);
    }
}

int main()
{
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	R=read();C=read();N=read();M=read();
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            map[i][j]=read();
    dfs(0,R);
    printf("%d",ans);
}
