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

const int N = 500000 + 5;

int n, k;

int sum[N][2];
int a[N];

struct atom {
  int p;
  int val;

  bool operator < (const atom &rhs) const {
    return val < rhs.val;
  }
} p[N];

bool del[N];

inline int lowerbd(int l, int r, int val) {
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (p[mid].val >= val) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}


inline int upperbd(int l, int r, int val) {
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (p[mid].val <= val) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}

int main() {
  freopen("omega.in", "r", stdin);
  freopen("omega.out", "w", stdout);
  n = read();
  k = read();
  char str[3];
  for (int i = 0; i < n; ++i) {
    scanf("%s", str);
    if (str[0] == 'A') {
      a[i] = 0;
    } else {
      a[i] = 1;
    }
    sum[i][0] = sum[i - 1][0] + (a[i] == 0);
    sum[i][1] = sum[i - 1][1] + (a[i] == 1);
  }
  for (int i = 0; i < n; ++i) {
    p[i].p = i;
    p[i].val = sum[i][1] - sum[i][0];
  }
  sort(p, p + n);
  /*for (int i = 0; i < n; ++i) {
    printf("%d %d\n", p[i].p, p[i].val);
    }*/
  int low = -k;
  int high = k;
  int l = 0;
  int r = n - 1;
  while (p[l].val < low) {
    ++l;
  }
  while (p[r].val > high) {
    --r;
  }
  int cnt = 0;
  int end = 0;
  int now = 0;
  while (end < n) {
    for (int i = l; i <= r; ++i) {
      if (del[p[i].p]) {
	continue;
      }
      end = max(end, p[i].p);
    }

    del[end] = 1;
    ++cnt;
    if (end >= n) {
      break;
    }
    int det = (sum[end][1] - sum[now - 1][1]) - (sum[end][0] - sum[now - 1][0]);
    low -= det;
    high -= det;
    l = lowerbd(0, n - 1, low);
    r = upperbd(0, n - 1, high);
    ++end;
    now = end;
  }
  printf("%d\n", cnt);
  return 0;
}
