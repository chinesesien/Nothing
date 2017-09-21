#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);++i)
#define per(i,a,n) for (int i=(n)-1;i>=(a);--i)

inline int read() {
  int f=1,x=0; char ch=getchar();
  while (ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
  while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return f*x;
}

const int N=16+1;

int n,m,x,y;
int v[N][N];
int f[N],tot;

struct node {
  int s,sum[N];
} r[15005],l[15005];

int topr,topl;

int main() {
  freopen("alpha.in","r",stdin);
  freopen("alpha.out","w",stdout);
  x=read(),y=read(),n=read(),m=read();
  rep (i,0,x) rep (j,0,y) v[i][j]=read();
  int lim=(1<<max(x,y));
  rep (s,0,lim) {
    tot=0; rep (i,0,N) if (s&(1<<i)) f[tot++]=i;
    if (tot==n) {
      r[topr].s=s;
      rep (i,0,y) rep (j,1,tot) r[topr].sum[i]+=abs(v[f[j]][i]-v[f[j-1]][i]);
      ++topr;
    }
    if (tot==m) {
      l[topl].s=s;
      rep (i,0,x) rep (j,1,tot) l[topl].sum[i]+=abs(v[i][f[j]]-v[i][f[j-1]]);
      ++topl;
    }
  }
  int ans=2e9;
  int now=0;
  node *lptr=l;
  while (lptr!=l+topl) {
    node *rptr=r;
    while (rptr!=r+topr) {
      now=0;
      rep (k,0,N) {
        if (lptr->s&(1<<k)) now+=rptr->sum[k];
        if (rptr->s&(1<<k)) now+=lptr->sum[k];
        if (now>ans) break;
      }
      ++rptr;
      ans=min(ans,now);
    }
    ++lptr;
  }
  printf("%d\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
