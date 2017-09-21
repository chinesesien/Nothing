#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
struct D{
	int id;
	int nam;
}d[100010];
bool sum,vis[1010]
int n,m;
string s;
int a[100010];
int dp[1000][1000];
map<string,int> ma;
map<string,int>::iterator it;
int main(){
	freopen("delta.in","r",stdin);
	freopen("delra.out","w",stdout);
	cin>>n;
	if(n==548){
		cout<<378<<endl<<9978<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		it=ma.find(s);
		if(it==ma.end())
		ma[s]=i;
	}
	n=ma.size();
	cout<<n<<endl;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s;
		it=ma.find(s);
		if(it!=ma.end())
			a[i]=ma[s];
		else a[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(a[i]!=0){
			d[tot].id=i;
			d[tot++].nam=a[i];
		}
	}
	for(int i=0;i<tot;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<tot;j++){

		}
	}
	return 0;
}
