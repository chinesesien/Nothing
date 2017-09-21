#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,A=0,B=0;
char a[500010];
int main(){
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		scanf("%c ",&a[i]);
		if(a[i]=='A') A++;
		else B++;
	}
	int ans=abs(A-B)/k;
	if(abs(A-B)%k!=0) ans++;
	printf("%d\n",ans);
	return 0;
}
