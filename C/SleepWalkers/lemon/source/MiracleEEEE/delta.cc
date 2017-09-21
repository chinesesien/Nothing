#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int Length = 30 + 3;
const int N = 1000 + 5;
const int M = 100000 + 5;
const int mod = 10007;

map <string, int> mp;

int n, m;

int p[] = {31, 23, 26, 31, 39, 41, 19, 17, 37, 41, 29};
/*
ll hash(string &str) {
  ll ret = 1;
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    ret = ret * p[i] + str[i] - 'a' + 1;
  }
  return ret;
}

struct atom {
  string l;
  int id;
};

int tot;

vector <atom> s[mod];

inline bool _find(string &str) {
  ll to = hash(str) % mod;
  for (int i = 0; i < s[to].size(); ++i) {
    if (s[to][i].l.length() != str.length()) {
      continue;
    }
    bool flg = true;
    for (int j = 0; j < str.length(); ++j) {
      if (str[j] != s[to][i].l[j]) {
	flg = false;
	break;
      }
    }
    if (flg) {
      return true;
    }
  }
  return false;
}

inline void _insert(string &str) {
  ll to = hash(str) % mod;
  atom a;
  a.l = str;
  a.id = ++tot;
  s[to].push_back(a);
}
*/
int c[M];

int vis[M];
int cnt;
int tot;

inline int check() {
  for (int i = 0; i < m; ++i) {
    if (!vis[c[i]] && c[i] != tot + 1) {
      vis[c[i]] = 1;
      ++cnt;
      //printf("%d\n", c[i]);
    }
  }
  return cnt;
}

string str;

int main()
{
  freopen("delta.in", "r", stdin);
  freopen("delta.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    /*
    if (_find(str)) {
      continue;
    } else {
      _insert(str);
    }
    */
    if (mp.find(str) != mp.end()) {
      continue;
    }
    mp[str] = ++tot;
  }
  cin >> m;
  //printf("%d\n", m);
  //printf("%d\n", tot);
  for (int i = 0; i < m; ++i) {
    cin >> str;
    /*
    if (!_find(str)) {
      c[i] = tot + 1;
    } else {
      int id = 0;
      int to = hash(str) % mod;
      for (int j = 0; j < s[to].size(); ++j) {
        if (s[to][j].l.length() != str.length()) {
	  continue;
	}
	bool flg = 1;
	for (int k = 0; k < str.length(); ++k) {
	  if (str[k] != s[to][j].l[k]) {
	    flg = false;
	  }
	}
	if (flg) {
	  id = s[to][j].id;
	  break;
	}
      }
    */
    if (mp.find(str) == mp.end()) {
      c[i] = tot + 1;
      continue;
    }
    c[i] = mp[str];
	// }
  }
  //printf("%d\n", mp.size());
  printf("%d\n", check());
  
  memset(vis, 0, sizeof(vis));

  int l = 0;
  int r = 0;

  vis[c[0]] = 1;

  if (cnt == 1) {
    puts("1");
    return 0;
  }

  int now = (c[0] == tot + 1) ? 0 : 1;
  int ans = m + 1;
  while (l <= r && l < m && r < m) {
    //printf("%d %d\n", l, r);
    if (now < cnt) {
      if (!vis[c[r + 1]] && c[r + 1] != tot + 1) {
	++now;
      }
      ++vis[c[r + 1]];
      ++r;
    } else { // now == cnt
      ans = min(ans, r - l + 1);
      if (vis[c[l]] == 1 && c[l] != tot + 1) {
	--now;
      }
      --vis[c[l]];
      ++l;
    }
  }
  printf("%d\n", ans);
  return 0;
}
//378
//9978
