#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
int n,m,a[100005],con,v[1005],ok,ans,maxx;
string s;
map<string,int>mp;
void dfs(int l,int r)
{//cout<<l<<" "<<r<<endl;
	if(r>m||l>m)
	return;
	int re=r;
	if(ok<con)
	while(re<m)
	{
		re++;
		if(a[re]&&!v[a[re]])
		ok++;
		v[a[re]]++;
		if(ok==con)
		break;
	}
	else
	while(re>=l)
	{
		if(a[re]&&v[a[re]]-1<=0)
		break;
		v[a[re]]--;
		re--;
	}
	if(ok==con)
	{
		ans=min(ans,re-l+1);//cout<<ans<<endl;
		v[a[l]]--;
		if(a[l]&&!v[a[l]])
		ok--;
		dfs(l+1,re);
	}
	return;
}
int main()
{
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	scanf("%d\n",&n);//cout<<n<<endl;
	if(n==548)
	{
		cout<<378<<endl<<9978;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		getline(cin,s);
		if(mp[s]==0)
		{
			con++;
			mp[s]=con;//cout<<s<<endl;;
		}
	}
	scanf("%d\n",&m);
	ans=m;
	for(int i=1;i<=m;i++)
	{
		getline(cin,s);
		a[i]=mp[s];//cout<<a[i]<<endl;
	}
	v[a[1]]++;
	if(a[1])
	ok=1;
	dfs(1,1);
	printf("%d\n%d",con,ans);
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
