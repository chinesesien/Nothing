#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define maxn 20
#define abs(i) ((i)>=0?(i):-(i))
const int INF=0x3f3f3f3f;
int mp[maxn][maxn],sel[maxn];
int dp[maxn][maxn];
int n,m,r,c,ans;

int readin(){
    int x=0,s=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*s;
}

void solve(){
    memset(dp,INF,sizeof(dp));
    for(int i=1;i<=c;i++){
	int w=0;
	for(int j=2;j<=n;j++)
	    w+=abs((mp[sel[j]][i]-mp[sel[j-1]][i]));
	dp[1][i]=w;
    }
    for(int i=2;i<=m;i++)
	for(int j=i;j<=c;j++)
	    for(int k=1;k<j;k++){
		int w=0;
		for(int h=1;h<=n;h++){
		    w+=abs((mp[sel[h]][k]-mp[sel[h]][j]));
		    if(h>1)w+=abs((mp[sel[h]][j]-mp[sel[h-1]][j]));
		}
		dp[i][j]=min(dp[i][j],dp[i-1][k]+w);
	    }
    /*if(sel[1]==4&&sel[2]==5){
	for(int i=1;i<=m;i++,puts(""))for(int j=1;j<=c;j++)cout<<dp[i][j]<<' ';
	}*/
    for(int i=m;i<=c;i++)ans=min(ans,dp[m][i]);
}

void dfs(int p,int last){
    if(p>n){
	solve();
	return ;
    }
    for(int i=last+1;i<=r;i++){
	sel[p]=i;
	dfs(p+1,i);
    }
}
    

int main(){
    freopen("alpha.in","r",stdin);
    freopen("alpha.out","w",stdout);
    r=readin();c=readin();n=readin();m=readin();
    for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	    mp[i][j]=readin();
    ans=INF;
    dfs(1,0);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
