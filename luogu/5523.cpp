// Problem: P5523 [yLOI2019] 珍珠
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5523
// Memory Limit: 500 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
#include <cstring>

namespace Maker {

typedef unsigned int uit;

bool __sp;
uit __x, __y, __z;
int __type, __k, __m;

const int L = 1 << 21;
char buf[L], *front = buf, *end = buf;
char GetChar() {
  if (front == end) {
    end = buf + fread(front = buf, 1, L, stdin);
    if (front == end) return -1;
  }
  return *(front++);
}

template <typename T>
inline void qr(T &x) {
  char ch = GetChar(), lst = ' ';
  while ((ch > '9') || (ch < '0')) lst = ch, ch = GetChar();
  while ((ch >= '0') && (ch <= '9'))
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = GetChar();
  if (lst == '-') x = -x;
}

template <typename T>
inline void Begin(const T &x) {
  __type = x % 10;
  qr(__x);
  qr(__y);
  qr(__z);
  qr(__m);
  __sp = (__type == 3) || (__type == 4);
  __type &= 1;
}

inline uit __Next_Integer() {
  __x ^= __y << (__z & 31);
  __y ^= __z >> (__x & 31);
  __z ^= __x << (__y & 31);
  __x ^= __x >> 5;
  __y ^= __y << 13;
  __z ^= __z >> 6;
  return __x;
}

inline uit Rand() { return __Next_Integer(); }

template <typename Tx, typename Ty, typename Tz>
inline void Get_Nextline(Tx &x, Ty &y, Tz &z) {
  if (__m) {
    --__m;
    x = 0;
    y = 0;
    z = 0;
    qr(x);
    qr(y);
    qr(z);
    if (x == 0) {
      ++__k;
    }
  } else {
    x = Rand() & 1;
    y = Rand() & 1;
    if (__k == 0) {
      x = 0;
    }
    if (x == 0) {
      ++__k;
      if (__sp) {
        z = __type;
      } else {
        z = Rand() & 1;
      }
    } else {
      int dk = __k >> 1;
      if (dk == 0) {
        z = 1;
      } else {
        z = Rand() % dk + dk;
      }
    }
  }
}

}  // namespace Maker

const int maxn = 10000000;
int lh[maxn + 5], rh[maxn + 5];
int lhl[maxn + 5], rhl[maxn + 5];
int lhr[maxn + 5], rhr[maxn + 5];
int ltop = maxn, rtop = 1;

void insert(int y, int z) {
  if (y == 0) {
    lh[ltop] = z;
    if (z == 0) {
      lhl[ltop] = ltop;
      for (int i = ltop + 1; lh[i] && i <= maxn; i++) lhl[i] = ltop;
      lhr[ltop] = ltop;
    } else
      lhr[ltop] = lhr[ltop + 1];
    ltop--;
  } else {
    rh[rtop] = z;
    if (z == 0) {
      rhr[rtop] = rtop;
      for (int i = rtop - 1; rh[i] && i > 0; i--) rhr[i] = rtop;
      rhl[rtop] = rtop;
    } else
      rhl[rtop] = rhl[rtop - 1];
    rtop++;
  }
}
int query(int y, int z) {
  if (y == 0) {
    if (ltop + z <= maxn) {
      int pos = ltop + z;
      if (lhl[pos] == -1)
        return z % 2;
      else {
        int npos = lhl[pos];
        return (pos - npos + (npos != ltop + 1)) % 2;
      }
    } else {
      int pos = (ltop + z) - maxn;
      if (rhl[pos] == -1) {
        if (lhl[maxn] == -1)
          return z % 2;
        else {
          int npos = lhl[maxn];
          return (ltop + z - npos + (npos != ltop + 1)) % 2;
        }
      } else {
        int npos = rhl[pos];
        return (pos - npos + (npos != 1 || ltop != maxn)) % 2;
      }
    }
  } else {
    if (rtop - z > 0) {
      int pos = rtop - z;
      if (rhr[pos] == -1)
        return z % 2;
      else {
        int npos = rhr[pos];
        return (npos - pos + (npos != rtop - 1)) % 2;
      }
    } else {
      int pos = maxn + (rtop - z);
      if (lhr[pos] == -1) {
        if (rhr[1] == -1)
          return z % 2;
        else {
          int npos = rhr[1];
          return (maxn - pos + 1 + npos - (npos == rtop - 1)) % 2;
        }
      } else {
        int npos = lhr[pos];
        return (npos - pos + (npos != maxn || rtop != 1)) % 2;
      }
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  Maker::Begin(n);
  memset(lhl, -1, sizeof(lhl));
  memset(lhr, -1, sizeof(lhr));
  memset(rhl, -1, sizeof(rhl));
  memset(rhr, -1, sizeof(rhr));
  int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
  int cnt = 0;
  for (int k = 1; k <= n; k++) {
    int x, y, z;
    Maker::Get_Nextline(x, y, z);
    if (x == 0)
      insert(y, z);
    else {
      cnt++;
      int res = query(y, z);
      res1 += (res == 1);
      res2 += (k % 2 == 1 && res == 0);
      res3 += (k % 2 == 0 && res == 1);
      res4 += (k % 1024 == 0 && res == 0);
    }
  }
  printf("%d %d %d %d\n", res1, res2, res3, res4);
  return 0;
}