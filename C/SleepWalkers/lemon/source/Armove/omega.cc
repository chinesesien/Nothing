#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define maxn 500050
#define ll long long 
#define inf 500050
using namespace std;
ll n,m,l,ans;
ll f[600010];
string a[600010];
int main()
{
	ll x,y;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    l=0;
    while(l!=n)
    {
        for(ll i=1;i<=n;i++)
        f[i]=0;
        x=0;
        y=0;
        for (ll i=l+1;i<=n;i++)
        {
            if(a[i]=="A")
            	x++;
            else
				y++;
            if(abs(x-y)<=m||x==0||y==0)
            	f[i]=1;
        }
        for(ll i=n;i>=l;i--)
        	if(f[i]==1)
        	{
            	ans++;
            	l=i;
            	break;
        	}
    }
    cout<<ans<<endl;
    return 0;
}
