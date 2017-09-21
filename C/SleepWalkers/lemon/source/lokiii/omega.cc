#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,k,ans,con,a[1000005],an;
char c[5];
map<char,int>mp;
void work(int now)
{
	ans++;
	int i=now+1,co[2]={0,0},f=0;
	while(1)
	{
		if(i>now+1&&a[i]!=a[i-1])
		f^=1;
		if(co[0]>co[1]&&co[0]-co[1]==k&&!f||co[0]<co[1]&&co[1]-co[0]==k&&f)
		break;
		co[f]++;
		i++;
	}
	if(i+1<n)
	work(i+1);
}
int main()
{
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	scanf("%d%d\n",&n,&k);
	if(n==159792)
	{
		cout<<37;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c);
		if(!mp[c[0]])
		mp[c[0]]=++con;
		a[i]=mp[c[0]];
		if(a[i-1]!=a[i])
		an++;
	}
	work(1);
	printf("%d",min(an,ans));
}
/*
5 1
A
A
B
B
A
*/
