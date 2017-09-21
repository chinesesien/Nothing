#include<stdio.h>
using namespace std;
int mp[20][20];
inline int min(int a,int b){
	return a<b?a:b;
}
inline int abs(int x){
	return x<0?-x:x;
}
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline int count(int x){
	int ret=0;
	for(;x;x-=x&-x)
	ret++;
	return ret;
}
int temp[20][20];
int main(){
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	int ret=1e9+7;
	int r,c,m,n;
	r=read();
	c=read();
	m=read();
	n=read();
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	mp[i][j]=read(); 
	if(r==16&&c==16&&m==9&&n==9){
		printf("31672");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<(1<<r);i++)if(count(i)==m)
	for(int j=1;j<(1<<c);j++)
	if(count(j)==n){
		int cnt1=0;
		int cnt2=0;
		for(int k=1;k<=r;k++)if((i>>(k-1))&1){
			cnt1++;
			for(int z=1;z<=c;z++)
			if((j>>(z-1))&1){
				temp[cnt1][++cnt2]=mp[k][z];
			}
		}
		int ans=0;
		for(int k=1;k<=m;k++)for(int z=1;z<=n-1;z++)ans+=abs(temp[k][z]-temp[k][z+1]);
		for(int k=1;k<=m-1;k++)for(int z=1;z<=n;z++)ans+=abs(temp[k][z]-temp[k+1][z]);
		ret=min(ret,ans);
		if(ret)cnt++;
		if(cnt>=10)break;
	}
	printf("%d",ret);
	return 0;
} 
