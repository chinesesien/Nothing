#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 20;
int r,c,n,m;
int mp[maxn][maxn],cost[maxn][maxn][maxn],w[maxn][maxn],wc[maxn],f[maxn][maxn],ans;

inline int num(int x){
	int cnt = 0;
	for(int i=0;i<r;i++)
		if(x>>i&1) cnt++;
	return cnt;
}

inline int min(int a,int b){
	return a<b ? a : b;
}

inline int max(int a,int b){
	return a>b ? a : b;
}

inline void show(int state){
	cout<<"++++++++++++++\n";
	for(int i=0;i<r;i++)
		if(state>>i&1) cout<<i+1<<' '; cout<<endl;
	for(int i=1;i<=c;i++) cout<<wc[i]<<' '; cout<<endl;
	for(int i=1;i<=c;i++){
		for(int j=1;j<=c;j++)
			cout<<w[i][j]<<' ';
		cout<<endl;
	}
}

int main(){
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	cin>>r>>c>>n>>m;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>mp[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			for(int k=j+1;k<=c;k++)
				cost[i][j][k] = max(mp[i][j]-mp[i][k],mp[i][k]-mp[i][j]);
	ans = 999999999;
	//枚举行选取状态
	for(int state = (1<<r)-1;state>=0;state--){
		if(num(state) != n) continue;
		//计算列之间花费
		memset(w,0,sizeof(w));
		for(int i=0;i<r;i++)
			if(state>>i&1) //判断是否选取该行
				for(int j=1;j<=c;j++)
					for(int k=1;k<=c;k++)
						w[j][k]+=cost[i+1][j][k];
		//计算选取列的花费
		memset(wc,0,sizeof(wc));
		int p,q=0;
		while(q<r && !(state>>q&1)) q++;		
		while(q<r){
			p = q++;
			while(q<r && !(state>>q&1)) ++q;
			if(q == r) break;
			for(int i=1;i<=c;i++) wc[i] += max(mp[p+1][i]-mp[q+1][i],mp[q+1][i]-mp[p+1][i]);
		}
   //show(state)
		//dp
		memset(f,0x3f3f3f,sizeof(f));
		for(int i=1;i<=c;i++) f[i][1] = wc[i];
		for(int j=2;j<=m;j++)
			for(int i=j;i<=c;i++)
				for(int k=j-1;k<i;k++)
					f[i][j] = min(f[i][j],f[k][j-1]+w[k][i]+wc[i]);
		//更新答案
		for(int i=m;i<=c;i++)
			ans = min(ans,f[i][m]);
	}
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
