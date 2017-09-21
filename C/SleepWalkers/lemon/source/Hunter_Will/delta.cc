#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

#define maxn 200000
struct str{
    char buf[100];
    char& operator [] (int x){
	return buf[x];
    }
    friend bool operator < (str a,str b){
	return strcmp(a.buf,b.buf)<0;
    }
};

map<str,int>mp;
int n,m,a[maxn],tot,b[maxn],p[maxn],c[maxn],tmp1[maxn],cnt;
int vis[maxn];

void calc(int x[],int d[],int g[]){
    memset(tmp1,-1,sizeof(tmp1));
    for(int i=1;i<=m;i++){
	if(x[i]){
	    d[i]=tmp1[x[i]];
	    tmp1[x[i]]=i;
	}
    }
    //for(int i=1;i<=m;i++)cout<<d[i]<<' ';cout<<endl;
    memset(tmp1,-1,sizeof(tmp1));
    for(int i=m;i>0;i--){
	if(x[i]){
	    g[i]=tmp1[x[i]];
	    tmp1[x[i]]=i;
	}
    }
    //for(int i=1;i<=m;i++)cout<<g[i]<<' ';cout<<endl;
}
	    

int main(){
    freopen("delta.in","r",stdin);
    freopen("delta.out","w",stdout);
    int ans;
    str tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%s",tmp.buf);
	if(mp.find(tmp)==mp.end())mp[tmp]=++cnt;
	//cout<<tmp.buf<<"->"<<mp[tmp]<<endl;
    }
    scanf("%d",&m);ans=m;
    for(int i=1;i<=m;i++){
	scanf("%s",tmp.buf);
	if(mp[tmp]==0)a[i]=0;
	else {a[i]=mp[tmp];if(!vis[mp[tmp]])tot++,vis[mp[tmp]]=1;}
	c[i]=a[i];
    }
    //for(int i=1;i<=m;i++)cout<<a[i]<<' ';cout<<endl;
    reverse(c+1,c+m+1);
    calc(a,b,p);
    int l=1,r=m;
    for(l=1;l<=m;l++)
	if(a[l]){
	    if(p[l]!=-1&&p[l]<=m&&p[l]>l);
	    else break;
	}
    for(r=m;r>0;r--)
	if(a[r]){
	    if(b[r]!=-1&&b[r]>=l&&b[r]<r);
	    else break;
	}
    ans=min(ans,r-l+1);
    //for(int i=1;i<=m;i++)cout<<p[i]<<' ';cout<<endl;
    //for(int i=1;i<=m;i++)cout<<b[i]<<' ';cout<<endl;
    calc(c,b,p);
    for(l=1;l<=m;l++)
	if(c[l]){
	    if(p[l]!=-1&&p[l]<=m&&p[l]>l);
	    else break;
	}
    for(r=m;r>0;r--)
	if(c[r]){
	    if(b[r]!=-1&&b[r]>=l&&b[r]<r);
	    else break;
	}
    ans=min(ans,r-l+1);
    cout<<tot<<endl<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
	    
