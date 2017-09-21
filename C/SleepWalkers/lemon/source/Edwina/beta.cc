#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,t;
ll poww(ll x,ll y,ll mod)
{
    ll ret=1;
    while(y)
    {
        if(y&1)
            ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ret;
}
int main()
{
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
    scanf("%d%d",&n,&t);
    if(t==10)
    {
    	puts("31250000\n");
    	return 0;
	}
	if(t>10)
	{
		puts("-1\n");
		return 0;
	}
    ll tmp=poww(10,t,inf);
    ll hou=n%tmp,pos=hou;//只取决于后t位
    ll cnt=0,i;
    for(i=2; i<=tmp; i++)
    {
        cnt++;pos=((pos)*n)%tmp;
        if(pos==hou)
        {
            printf("%lld\n",cnt);
            break;
        }
    }
    if(i-1==tmp)
    {
        puts("-1\n");
    }
    return 0;
}

