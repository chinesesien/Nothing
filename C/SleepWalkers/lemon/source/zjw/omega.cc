#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a[500005];
int b[500005];
int n,k;
int main()
{
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	cin>>n>>k;
	int j=0;
	char ch='C',c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c!=ch)j++;
		ch=c;
		if(c=='A')a[j]++;
		else a[j]--;
	}
	int n=j;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		int loc=i;
		for(int j=i+1;j<=n;j++)
		{
			sum+=a[j];
			if(abs(sum)<=k)loc=j;
		}
		ans++;
		i=loc;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
