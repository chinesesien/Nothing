#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 

inline int read()
{
  int f = 1;
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f = (ch == '-') ? -1 : 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

using namespace std;

const int N = 1000 + 5;
const int M = 10000 + 5;
const int K = 30 + 5;

int n, m, mxk;

struct node {
  long long val;
  int u;
  int k;

  bool operator < (const node &rhs) const {
    return val > rhs.val;
  };

  node(long long _val, int _u, int _k) {
    val = _val;
    u = _u;
    k = _k;
  }
};

int head[N], tot;

struct edge {
  int nxt;
  int to;
  int val;
} e[M << 1];

inline void add(int u, int v, int val) {
  e[tot].nxt = head[u];
  e[tot].to = v;
  e[tot].val = val;
  head[u] = tot++;
}

long long dist[N][K];
int vis[N][K];

inline void dijkstra() {
  memset(dist, 0x3f3f, sizeof(dist));
  dist[1][0] = 0;
  priority_queue <node> que;
  que.push(node(0, 1, 0));
  while (!que.empty()) {
    int u = que.top().u;
    int k = que.top().k;
    que.pop();
    if (vis[u][k]) {
      continue;
    }
    vis[u][k] = 1;
    for (int i = head[u], v; ~i; i = e[i].nxt) {
      v = e[i].to;
      if (dist[v][k] > max(dist[u][k], 1ll * e[i].val)) {
	dist[v][k] = max(dist[u][k], 1ll * e[i].val);
	que.push(node(dist[v][k], v, k));
      }
      if (k + 1 <= mxk && dist[v][k + 1] > dist[u][k]) {
	dist[v][k + 1] = dist[u][k];
	que.push(node(dist[v][k + 1], v, k + 1));
      }
    }
  }
  return;
}

int main() {
  freopen("sigma.in", "r", stdin);
  freopen("sigma.out", "w", stdout);
  n = read();
  m = read();
  mxk = read();
  memset(head, -1, sizeof(head));
  for (int i = 0, u, v, w; i < m; ++i) {
    u = read();
    v = read();
    w = read();
    add(u, v, w);
    add(v, u, w);
  }
  dijkstra();
  long long ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i <= mxk; ++i) {
    ans = min(ans, dist[n][i]);
  }
  printf("%lld\n", ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
