#include <cstdio>
#include <cmath>
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

const int N=29;

double mat[N][N];

struct node {
  int type,val;
} p[1005];

int tot,cnt,fa[10005],head[10005];

inline int newnode(int type,int val) {
  p[++cnt].type=type,p[cnt].val=val;
  return cnt;
}

struct edge {
  int nxt,to;
} e[10005];

inline void add(int u,int v) {
  //printf("%d->%d\n",u,v);
  e[tot].to=v,e[tot].nxt=head[u],head[u]=tot++,fa[v]=u;
}

int n;
char str[100005];

void dfs(int x,int l,double s) {
  if (p[x].type!=-1) {
    if (p[x].type==1) mat[l][p[x].val]+=s;
    if (p[x].type==2) mat[l][n]+=-1.0*p[x].val*s;
    //printf("%d %d\n",x,p[x].type);
    //printf("%.3f\n",mat[l][n]);
    //printf("%.3f\n",s);
    return;
  }
  int cnt=0;
  for (int i=head[x];~i;i=e[i].nxt) ++cnt;
  for (int i=head[x],v;~i;i=e[i].nxt) {
    v=e[i].to,dfs(v,l,s*(1.0/cnt));
  }
}

bool flg[N];

void gauss()
{
  int k=0;
  rep(i,0,n) {
    int pivot=i;
    rep (j,k,n) if (abs(mat[j][i])>abs(mat[pivot][i])) pivot=j;
    rep (j,0,n+1) swap(mat[k][j],mat[pivot][j]);
    if (abs(mat[k][i])<1e-9) {
      flg[i]=1; continue;
    }
    rep(j,i+1,n+1) mat[i][j]/=mat[i][i];
    rep(j,0,n) if (i!=j) rep(k,i+1,n+1) mat[j][k]-=mat[j][i]*mat[i][k];
    ++k;
  }
}


int main() {
  freopen("gamma.in","r",stdin);
  freopen("gamma.out","w",stdout);
  n=read();
  rep (i,0,n) {
    tot=0,cnt=0,memset(head,-1,sizeof(head));
    int ptr=newnode(-1,0),len=0;
    while (true) {
      str[len++]=getchar();
      if (str[len-1]=='\n'||str[len-1]==EOF) break;
    }
    int l=0; while (str[l]!='[') ++l;
    int r=len-1; while (str[r]!=']') --r;
    ++l;
    rep (j,l,r) {
      if (str[j]==' ') continue;
      else if (str[j]>='a'&&str[j]<='z') add(ptr,newnode(1,str[j]-'a'));
      else if (str[j]=='-'||(str[j]>='0'&&str[j]<='9')) {
	int x=0,f=str[j]=='-'?-1:1;
	if (str[j]=='-') ++j;
	while (str[j]>='0'&&str[j]<='9') x=x*10+str[j]-'0',++j; --j;
	add(ptr,newnode(2,f*x));
      }
      else if (str[j]=='[') add(ptr,newnode(-1,0)),ptr=cnt;
      else ptr=fa[ptr];
    }
    mat[i][i]-=1;
    dfs(1,i,1);
  }

  gauss();
  rep (i,0,n) {
    printf("%c = ",i+'a');
    if (flg[i]) puts("Unknown");
    else printf("%.3f\n",mat[i][n]);
  }
  return 0;
}
