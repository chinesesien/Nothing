#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

#define rep(i,a,n) for (int i=(a);i<(n);++i)
#define per(i,a,n) for (int i=(n)-1;i>=(a);--i)

inline ll read() {
  ll f=1,x=0; char ch=getchar();
  while (ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
  while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return f*x;
}

int exi[10005];

int main() {
  freopen("beta.in","r",stdin);
  freopen("beta.out","w",stdout);
  ll n=read(),t=read();
  t=pow(10,t);
  ll b=n%t;
  exi[b]=3;
  int cnt=10000000;
  int len=1;
  while (cnt--) {
    exi[b]--;
    if (exi[b]==1) {
      printf("%d\n",len-1);
      return 0;
    }
    b=b*n%t;
    ++len;
  } 
  printf("%d\n",-1);
  return 0;
}
