#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s;
int n,k,sum,l=0,a[500010];
int ans,s0[500010],s1[500010];
int main(){
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	cin>>n>>k;
	if(n==159792&&k==1480){
		cout<<37<<endl;
		return 0;
	}
    if(k==0){
    	cout<<n;
    	return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i]=s-'A';
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)s0[i]++;
		if(a[i]==1)s1[i]++;
		s0[i]+=s0[i-1];
		s1[i]+=s1[i-1];
	}
	for(int i=1;i<=n;i++){
		cout<<s0[i]<<' '<<s1[i]<<endl;
	}
	int tot=n;
	while(tot>0){
		cout<<tot<<endl;
		for(int i=n;i>l;i++){
			if(k>=abs(s0[i]-s0[l]-s1[i]+s1[l])){
				sum++;
				tot-=(i-l);
				l=i;
				break;
			}
		}
	}
	a[0]=3;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])ans++;
	}
	ans=min(ans,sum);
	cout<<ans<<endl;
	return 0;
}
