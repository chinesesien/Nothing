#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define N 1100
#define M 100100
#define INF  
bool ex[N];
int n,m;
string in;
map<string,int> mp;
int a[M];
int cnt[M];
int re;
int ans=M;

int kd;
int main()
{
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	mp.clear();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in;
		mp[in]=i;
	}
	cin>>m;
	kd=0;
	memset(ex,0,sizeof(ex));
	for(int i=1;i<=m;i++)
	{
		cin>>in;
		if(mp.count(in)>0)
		{
			a[i]=mp[in];
			if(!ex[mp[in]])
			{
				kd++;
				ex[mp[in]]=1;
			}
		}
		else
			a[i]=-1;
	}
	int l=0,r=0;
	re=kd;
	cout<<kd<<endl;
	memset(cnt,0,sizeof(cnt));
	while(r<=m)
	{
		while(r<=m&&re)
		{
			r++;
			if(a[r]==-1)
				continue;
			if(cnt[a[r]]==0)
			{
				cnt[a[r]]++;
				re--;
			}
			else
				cnt[a[r]]++;
		}
		while(l<=r&&re==0)
		{
			l++;
			if(a[l]==-1)
				continue;
			cnt[a[l]]--;
			if(cnt[a[l]]==0)
				re++;
			ans=min(ans,r-l+1);
		}
	}
	cout<<ans<<endl;
	return 0;	
	
} 
