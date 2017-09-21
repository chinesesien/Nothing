#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

long long t,n,dp[100000],ans=0;
struct ll{
	long long a,b,c;
}sc[53];

bool cmp(ll a,ll b){
	return a.b*b.c<b.b*a.c;
}


int main(){
	scanf("%lld%lld",&t,&n);
	for(long long i=0;i<n;i++) scanf("%lld",&sc[i].a);
	for(long long i=0;i<n;i++) scanf("%lld",&sc[i].b);
	for(long long i=0;i<n;i++) scanf("%lld",&sc[i].c);
	sort(sc,sc+n,cmp);
	for(long long i=0;i<n;i++){
		for(long long j=t;j>=sc[i].c;j--){
			dp[j]=max(dp[j],dp[j-sc[i].c]+sc[i].a-j*sc[i].b);
		}
	}
	for(long long i=0;i<t;i++) ans=max(ans,dp[i]);
	printf("%lld",ans);

	return 0;
}
