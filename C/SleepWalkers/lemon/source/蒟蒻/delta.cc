#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define maxn 1010
#define ll long long 
#define inf 1e9
using namespace std;
int n,m,mod=1313131,sum=0,ans=inf;
int a[maxn],t[100010],vis[3000010],num[3000010];
int p[11]={3,13,31,131,313,1313,3131,13131,31313,131313};
int hash_func(char *s)
{
	int res=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		res+=(s[i]-17)*p[i];
	}
	res%=mod;
	return res+1;
}
int main()
{
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	int x;
	char ch[15];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		a[i]=hash_func(ch);
//		cout<<a[i]<<endl;
		vis[a[i]]=-1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",ch);
		x=hash_func(ch);
//		cout<<x<<endl;
		if(!vis[x])t[i]=0;
		else t[i]=x;
		if(vis[x]==-1)
		{
			vis[x]=1;
			sum++;
		}
	}
	int l=1,r=1,cnt=sum;
	if(sum==0)
	{
		printf("%d\n%d\n",sum,0);
		return 0;
	}
	while(true)
	{
		if(cnt==0)
		{
			while(t[l]==0)l++;
			if(ans>r-l)
			{
				ans=r-l;
//				cout<<l<<" ====== "<<r<<endl;
//				cout<<num[t[l]]<<" ------ "<<num[t[r]]<<endl;
			}
			if(num[t[l]]>1)
			{
				num[t[l]]--;
				l++;
			}
			else if(num[t[l]]==1)
			{
				num[t[l]]--;
				cnt++;
				l++;
			}
		}
		else
		{
			if(r==m+1)break;
			if(vis[t[r]])
			{
				num[t[r]]++;
				if(num[t[r]]==1)
				{
					cnt--;
				}
			}
			r++;
		}
	}
	printf("%d\n%d\n",sum,ans);
    return 0; 
} 
/*
3
lyy
dzh
xfbp
5
lyy
dzh
dzh
xfbp
lyy
*/
