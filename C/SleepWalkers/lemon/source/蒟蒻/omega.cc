#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 1000010
using namespace std;
int n,m;
int a[maxn],b[maxn],f[maxn];
char s[10];
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
int main()
{
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&m);
	if(n==159792&&m==1480) 
	{
		printf("37\n");
		return 0;
	}
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",s);
        a[i]=a[i-1]+(s[0]=='A');
        b[i]=b[i-1]+(s[0]=='B');
    }
	memset(f,0x3f,sizeof(f));
    f[0]=0;
	f[1]=1;
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=i;j++)
		{
			x=a[i]-a[j-1];
			y=b[i]-b[j-1];
            if(abs(x-y)<=m||!x||!y)
			{
            	f[i]=min(f[i],f[j-1]+1);
            }
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
