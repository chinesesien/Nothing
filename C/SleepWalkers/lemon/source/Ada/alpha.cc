#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 18;
int pic[N][N], ans=10000000, r, c, n, m;
int a[N], ccc[N], rr[N];

bool cmp(const int i, const int j) {
  return ccc[i]<ccc[j];
}

int op() {
  memset(ccc, 0, sizeof(ccc));
  for(int i=0; i<c; ++i) rr[i]=i;
  for(int j=0; j<c; ++j) 
    for(int i=1; i<n; ++i) 
      ccc[j]+=abs(pic[a[i]][j]-pic[a[i-1]][j]);
  sort(rr, rr+c, cmp);
  int vis[N];
  memset(vis, 0, sizeof(vis));
  for(int i=0; i<m; ++i) vis[rr[i]]=1;
  vector<int> v;
  for(int i=0; i<c; ++i) if(vis[i]) v.push_back(i);

  int x=0;
  for(int i=0; i<m; ++i) x+=ccc[v[i]];
  for(int i=0; i<n; ++i) 
    for(int j=1; j<m; ++j) 
      x+=abs(pic[a[i]][v[j]]-pic[a[i]][v[j-1]]);
  return x;
}

void dfs(int tot, int cnt) {
  if(cnt==n) {
    ans=min(ans, op());    
    return ;
  }
  if(r-tot+cnt<n) return;
  dfs(tot+1, cnt);
  a[cnt]=tot;
  dfs(tot+1, cnt+1);
}

int main() {
  freopen("alpha.in", "r", stdin);
  freopen("alpha.out", "w", stdout);
  scanf("%d%d%d%d", &r, &c, &n, &m);
  for(int i=0; i<r; ++i) 
    for(int j=0; j<c; ++j) 
      scanf("%d", &pic[i][j]);
  dfs(0, 0);
  printf("%d\n", ans);
}
