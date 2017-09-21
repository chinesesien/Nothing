//Problem.D Code By HYS.(Force)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
const int prime[10]={3,13,31,131,313,1313,3131,13131,31313,131313};
inline int strhash(const char* s){
    int t=0;
    for(int i=0;i<strlen(s);i++)
        t+=(s[i]-13)*prime[i];
    return t%1313131+1;
}
int a[1024],b[100007],n,m,cnt,ans=0x3F3F3F3F;
char str[16];
map<int,int> has,req;
inline void force(int x){
    int res=0,tmp=cnt;
    req=has;
    for(int i=x;i<=m;i++){
        if(req[b[i]]==1)req[b[i]]=-1,tmp--,res=i-x+1;
        if(tmp==0)break;
    }
    ans=min(ans,tmp==0?res:0x3F3F3F3F);
}
int main(){
    freopen("delta.in","r",stdin);
    freopen("delta.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",str),a[i]=strhash(str),has[a[i]]=-1;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",str),b[i]=strhash(str);
        if(has[b[i]]==-1)cnt++,has[b[i]]=1;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=m-cnt+1;i++)force(i);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}