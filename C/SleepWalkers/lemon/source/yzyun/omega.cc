#include<stdio.h>
#include<iostream> 
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdlib>
using namespace std;
typedef long long ll;
int n,k,k_;
int c[500100];
int sum[500100];
int main(){
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout); 
	scanf("%d%d",&n,&k);
	k_=(-1)*k;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='A'&&ch!='B')ch=getchar();
		if(ch=='A')c[i]=1;
		else c[i]=-1;
		sum[i]=sum[i-1]+c[i];
	}
	int ans=0;
	int last=1;
	while(last<n){
		for(int i=n;i>=last;i--){
			if(sum[i]<=k&&sum[i]>=k_){
				last=i+1;
				break;
			}
		}
		ans++;
		sum[last-1]=0;
		for(int i=last;i<=n;i++)
		sum[i]=sum[i-1]+c[i];
	}
	printf("%d",ans);
	return 0;
}  
