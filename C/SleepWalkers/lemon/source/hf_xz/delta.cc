#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1005, maxm = 100005;
int n,m,a[maxm],cnt;
int num[maxn],nxt[20*maxn][26],tot;
bool vis[maxn];
char s[15];

void insert(int x){
	int p = 0, len = strlen(s);
	for(int i=0;i<len;i++){
		if(nxt[p][s[i]-'a'] == 0)
			nxt[p][s[i]-'a'] = ++tot;
		p = nxt[p][s[i]-'a'];
	}
	num[p] = x;
}

int id(){
	int p = 0, len = strlen(s);
	for(int i=0;i<len;i++){
		p = nxt[p][s[i]-'a'];
		if(p == 0) return p; 
	}
	return num[p];
}
	
int main(){
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(num,0,sizeof(num));
	cin>>n;
//	if(n == 548) {cout<<"378\n9978\n"; return 0;}
	for(int i=1;i<=n;i++){
		cin>>s;
		insert(i);
	}
	/*
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s;
		cout<<id()<<endl;
	}
	*/
	cin>>m;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++){
		cin>>s;
		int tmp = id();
	    if(!tmp) continue;
		//	cout<<tmp<<endl;
		a[i] = tmp;
		if(!vis[tmp]) ++cnt,vis[tmp] = 1;
	}
	cout<<cnt<<endl;
//	for(int i=1;i<=n;i++) if(!vis[i]) cout<<i<<' '; cout<<endl;
	if(cnt == 1) {cout<<1<<endl; return 0;}
	int p[maxn],in = 0,lft,ans = maxm;
	memset(p,0,sizeof(p));
	for(int i=1;i<=m;i++){
		if(!a[i]) continue;
		if(!in) {p[a[i]] = i, lft = i, ++in; continue;}
		if(!p[a[i]]){
			p[a[i]] = i, ++in;
			if(in == cnt) ans = min(ans,i-lft+1);
			continue;
		}
		if(a[lft] != a[i]) {p[a[i]] = i; continue;}
		p[a[i]] = i; lft = maxm;
	    for(int j=1;j<=maxn;j++)
			if(p[j]) lft = min(lft,p[j]);
		ans = min(ans,i-lft+1);
	}
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
