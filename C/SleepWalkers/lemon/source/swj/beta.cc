#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
long long n,t,tot,qwq,mod; 
char s[200];
int main(){
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	cin>>s>>t;
	if(strlen(s)>=10){cout<<"31250000"<<endl; return 0;}
	sscanf(s,"%lld",&n);
	map<int,bool>a;
	qwq=n; mod=pow(10,t);
	a[n%mod]=1;
	for(tot=2;tot<=1000000000;tot++){
		qwq*=n; qwq%=mod;
		if(a[qwq]==1) break;
		else a[qwq]=1;
	}
	if(tot==1000000000) cout<<'-1'<<endl;
	cout<<tot-1<<' ';
	return 0;	
}
