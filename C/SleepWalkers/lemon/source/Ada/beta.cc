#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5], vis[10005];

int main() {
  freopen("beta.in", "r", stdin);
  freopen("beta.out", "w", stdout);
  int t;
  long long n;
  scanf("%lld%d", &n, &t);
  a[0]=1;
  for(int i=1; i<5; ++i) a[i]=a[i-1]*10;
  int num=n%a[t], ans=0, b=num;
  for(int kase=0; kase<10000; ++kase) {
    b*=num; b%=a[t];
    if(vis[b]) {ans=kase; break;}
    vis[b]=1;
  }
  if(ans) printf("%d\n", ans);
  else printf("-1\n");
  return 0;
}
