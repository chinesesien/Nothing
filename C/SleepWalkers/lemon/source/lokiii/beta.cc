#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,a[110],b[110],c[2][110],ans[110];
char s[110];
bool ok(int p[],int q[],int x)
{
	for(int i=1;i<=x;i++)
	if(p[i]!=q[i])
	return 0;
  	return 1;
}
void mul1(int x)
{
  	int last=0;
  	for(int i=1;i<=ans[0];i++)
    {
	    ans[i]=ans[i]*x+last;
	    last=ans[i]/10,ans[i]%=10;
	}
  	if(last>0)
	ans[++ans[0]]=last;
}
void mul(int w[],int p[],int q[])
{
	int last=0;
	w[0]=min(p[0]+q[0]-1,n);
  	for(int k=1;k<=w[0];k++)
    {
		w[k]=last;
    	for(int i=1;i<=p[0];i++)
        if(k+1-i>=1&&k+1-i<=q[0])
		w[k]+=p[i]*q[k+1-i];
      	last=w[k]/10,w[k]%=10;
    }
  	if(last)
	w[++w[0]]=last;
}
int get(int x)
{
	memcpy(c[0],b,sizeof(b));
	for(int i=1;i<=10;i++)
	{
      	mul(c[i%2],c[(i+1)%2],b);
      	if(ok(c[i%2],b,x))
	    {
	      	mul(c[i%2],c[(i-1)%2],a);
	      	if(!ok(c[i%2],a,x))
			{
				printf("-1\n");
  				exit(0);
  			}
	      	memcpy(b,c[(i-1)%2],sizeof(c[0]));
	      	return i;
		}
	}
  	
}
int main()
{
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	scanf("%s%d",s,&n);
	a[0]=strlen(s),n=min(a[0],n);
	for(int i=1;i<=n;i++)
	a[i]=s[a[0]-i]-'0';
	memcpy(b,a,sizeof(a));
	ans[0]=1,ans[1]=1;
	for(int i=1;i<=n;i++)
	mul1(get(i));
	for(int i=ans[0];i>=1;i--)
	printf("%d",ans[i]);
	return 0;
}
