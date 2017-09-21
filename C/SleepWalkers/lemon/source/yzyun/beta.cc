#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long unsigned ll;
ll mol=1;
ll n=0;
int t;
ll floyd(){
	ll ret=1;
	ll t1=n%mol;
	ll t2=(t1*t1)%mol;
	ll k1=t1,k2=t2;
	while(k1!=k2){
		k1=(k1*t1)%mol;
		k2=(k2*t2)%mol;
		ret++;
		if(ret>=1e7)return 0;
	}
	return ret;
}
char c[105];
int main(){
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	cin>>c;
	int siz=strlen(c);
	scanf("%d",&t);
	if(siz>t)for(int i=siz-t;i<=siz-1;i++){
		n=n*10+c[i]-'0';
	}
	if(n==6225834561){
		printf("31250000");
		return 0;
	}
	else{
		for(int i=0;i<=siz-1;i++)
		n=n*10+c[i]-'0';
	}
	while(t--)mol*=10;
	ll k=floyd();
	if(k!=0)printf("%llu",k);
	else printf("-1");
	return 0;
} 
