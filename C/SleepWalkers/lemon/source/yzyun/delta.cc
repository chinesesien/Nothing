#include<stdio.h>
#include<iostream> 
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdlib>
using namespace std;
typedef long long ll;
const ll mol=1e9+7;
const ll base=233333333;
int n,m;
ll t[1100];
ll temp[1100];
ll p[10100];
ll hash(){
	ll hash=0;
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c>='a'&&c<='z'){
		hash=(hash*base%mol+c-'a'+1)%mol;
		c=getchar(); 
	}
	return hash;
}
int vis[110000];
int main(){
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)t[i]=hash();
	for(int i=1;i<=n;i++)temp[i]=t[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)p[i]=hash();
	sort(temp+1,temp+1+n);
	int size=unique(temp+1,temp+1+n)-temp-1;
	for(int i=1;i<=n;i++){
		t[i]=lower_bound(temp+1,temp+1+size,t[i])-temp;
	}
	for(int i=1;i<=m;i++){
		int ret=lower_bound(temp+1,temp+1+size,p[i])-temp;
		if(temp[ret]!=p[i])p[i]=0;
		else p[i]=ret;
	}
	int ans=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)if(p[i]!=0){
		if(vis[p[i]]!=0){
			ans++;
		}
		vis[p[i]]++;
	}
	printf("%d\n",ans);
	memset(vis,0,sizeof(vis));
	int ans2=1e9;
	int cnt=0;
	int l=1,r=0;
	while(r<m){
		while(cnt<ans){
			r++;
			if(p[r]==0){ 
				continue;
			}
			if(!vis[p[r]]){
				cnt++;
		    }
		    vis[p[r]]++;
		    if(r==m)break;
		}
		if(cnt==ans)ans2=min(ans2,r-l+1);
		else break;
		for(;;l++){
			if(p[l]==0)continue;
			if(vis[p[l]]==1)break;
			vis[p[l]]--;
		}
		ans2=min(ans2,r-l+1);
		vis[p[l]]--;
		cnt--;
		l++;
	}
	printf("%d",ans2);
	return 0;
} 

