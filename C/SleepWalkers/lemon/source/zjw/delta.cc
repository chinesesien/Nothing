#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
map<string,int> mm;
int n,m;
int a[100005];
int vis[10000];
string s;
int main()
{
	freopen("delta.in","r",stdin);
        freopen("delta.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mm[s]=i;
	//	cout<<s<<' '<<mm[s]<<endl;
	}
	scanf("%d",&m);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
//		cout<<s<<' '<<mm[s]<<endl;
		if(mm.find(s)==mm.end())a[i]=-1;
		else 
		{
			if(!vis[mm[s]])
			{
				vis[mm[s]]=1;
				ans++;
				a[i]=mm[s];
			}
			else a[i]=mm[s];
		} 
	}
	memset(vis,0,sizeof(vis));
	int had=1,tail=1;
	int ext=0;
	int maxn=m;
	int nax=0;
	int now;
	while(a[had]==-1)had++;
	tail=had;
	now=a[had];
	vis[now]=1;
	nax=1;
	while(tail<=m)
	{
		tail++;
		if(a[tail]!=-1)
		{
			if(!vis[a[tail]])nax++;
			vis[a[tail]]++;
		}
		if(a[tail]==now)
		{
			had++;
			vis[now]--;
			while(a[had]==-1||vis[a[had]]>1)
			{
				had++;
				if(vis[a[had]]>1)vis[a[had]]--;
			}
			now=a[had];
		}
		if(nax==ans)maxn=min(maxn,tail-had+1);
	}
	while(vis[a[had]]>1||a[had]==-1)
	{
		vis[a[had]]--;
		had++;
	}
	maxn=min(maxn,tail-had+1);
	cout<<ans<<endl<<maxn;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
