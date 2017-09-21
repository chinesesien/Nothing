#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
const int M = 20005;
int head[N], nxt[M], to[M], w[M], tot;
int n, m, k, bina[M];
int done[N], d[N];

void add(int u, int v, int val) {
  to[++tot]=v;
  w[tot]=val;
  nxt[tot]=head[u];
  head[u]=tot;
}

int read() {
  int sum=0; 
  char c=getchar();
  while(c>'9' || c<'0') c=getchar();
  while(c>='0' && c<='9') {
    sum=sum*10+c-'0';
    c=getchar();
  }
  return sum;
}

struct Node {
  int u, p;
  bool operator < (const Node i) const {
    return p>i.p;
  }
};

bool dijk(int z) {
  memset(done, 0, sizeof(done));
  memset(d, -1, sizeof(d));
  priority_queue<Node> Q;
  d[1]=0;
  Q.push((Node) {1, 0});
  while(!Q.empty()) {
    Node x=Q.top(); Q.pop();
    int u=x.u;
    if(done[u]) continue;
    if(u==n) return 1;
    done[u]=1;
    for(int i=head[u]; i; i=nxt[i]) {
      int v=to[i];
	if(d[v]<0 || d[v]>d[u]) {
	  d[v]=d[u]; 
	  if(w[i]>z) d[v]++;
	  if(d[v]<=k)
	    Q.push((Node) {v, d[v]});
	}
    }
  }
  return 0;
}

int main() {
  freopen("sigma.in", "r", stdin);
   freopen("sigma.out", "w", stdout);
  n=read(), m=read(), k=read();
  for(int i=1; i<=m; ++i) {
    int u=read(), v=read(), val=read();
    add(u, v, val);
    add(v, u, val);
    bina[i]=val;
  }
  sort(bina, bina+m+1);
  int num=unique(bina, bina+m+1)-bina;
  int l=0, r=num-1;
  while(l<r) {
    int mid=l+(r-l)/2;   
    if(dijk(bina[mid])) r=mid;
    else l=mid+1;
  }
  if(l!=num)  printf("%d\n", bina[l]);
  else if(dijk(bina[num])) printf("%d\n", bina[num]);
  else printf("-1\n");
  return 0;
}
