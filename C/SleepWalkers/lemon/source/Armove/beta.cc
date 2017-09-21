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
int n=0,m,k;
int a[maxn],b[maxn],ans[maxn],d[maxn];
char c[maxn];
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
bool judge(int x)
{
    int s[maxn];
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=b[0];j++)
            if(i+j-1>x)break;
            else
            {
                s[i+j-1]+=d[i]*b[j];
                s[i+j]+=s[i+j-1]/10;
                s[i+j-1]%=10;
            }
    if(d[x]==s[x])return true;
    return false;
}
void get()
{
    int s[maxn];
    memset(s,0,sizeof(s));
    s[0]=a[0]+b[0]-1;
    for(int i=1;i<=a[0];i++)
        for(int j=1;j<=b[0];j++)
            if(i+j-1<=n)
            {
                s[i+j-1]+=a[i]*b[j];
                s[i+j]+=s[i+j-1]/10;
                s[i+j-1]%=10;
            }
    while(s[s[0]+1]>0)s[0]++;
    if(s[0]>n)s[0]=n;
    for(int i=0;i<=s[0];i++)
        b[i]=s[i];
}
void mul(int x)
{
    for(int i=1;i<=ans[0];i++)
          ans[i]*=x;
    for(int i=1;i<=ans[0];i++)
    {
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while(ans[ans[0]+1]>10)
    {
        ans[0]++;
        ans[ans[0]+1]+=ans[ans[0]]/10;
        ans[ans[0]]%=10;
    }
    if(ans[ans[0]+1]>0)ans[0]++;
}
void init()
{
    while(scanf("%c",&c[++n])&&c[n]!=' ');
    n--;
    scanf("%d",&k);
    for(int i=1;i<=n;i++)
        d[i]=c[n+1-i]-'0';
    if(n>k)n=k;
    if(n<k)
    {
          for(int i=n+1;i<=k;i++)
            d[i]=0;
          n=k;
    }
    for(int i=1;i<=n;i++)
        a[i]=b[i]=d[i];
    a[0]=b[0]=n;
    ans[0]=1;
    ans[1]=1;
}
void work()
{
    for(int i=1;i<=k;i++)
    {
        int now;
        if(judge(i))continue;
        for(now=2;now<=11;now++)
        {
            get();
            if(judge(i))
                break;
        }
        if(now>11)
        {
            printf("-1\n");
            return ;
        }
        mul(now);
        for(int j=b[0];j>=0;j--)
            a[j]=b[j];
    }
    for(int i=ans[0];i;i--)
        printf("%d",ans[i]);
    printf("\n");
}
int main()
{
    init();
    work();
    return 0; 
} 
/*
32 2
*/
