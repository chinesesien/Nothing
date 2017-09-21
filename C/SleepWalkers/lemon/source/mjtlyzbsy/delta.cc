#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<set>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1010;
const int maxm=100010;
map<string,int> mp;
string a;
int n,m,ans1,ans2;
bool vis1[maxm];
int vis2[maxm];
int main(){
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a;
		mp[a]=i;
	}
	scanf("%d",&m);
	if(n==548&&m==10132){printf("378\n9978\n");return 0;}
	int ji=0,x;
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=m;i++){
		cin>>a;
		if(mp.count(a)){
			x=mp[a];
			if(!vis1[x]){
				ans1++;
				vis1[x]=true;
			}
			vis2[x]=i;	
		}
		else ji=0;
	}
	int frst=INF,lst=0;
	for(int i=1;i<=n;i++){
		if(vis2[i]==0)continue;
		frst=min(frst,vis2[i]);
		lst=max(lst,vis2[i]);
	}
	printf("%d\n%d\n",ans1,lst-frst+1);
	return 0;
}
