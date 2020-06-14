#include<bits/stdc++.h>

using namespace std;
#define MAXN 1000000

int par[MAXN] = {0};
int depth[MAXN] = {0};

void init(int n)
{
  for(int i=0; i<=n; i++) {
    par[i]=i;
    depth[i]=0;
  }
}

int find(int x)  //find root
{
  if(par[x]==x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

inline void unite(int x, int y)
{
  x = find(x);
  y = find(y);
  if(x==y)  return;  //same root

  if(depth[x] < depth[y]) {
    par[x] = y;  //x's parent is y
  } else {
    par[y] = x;  //y's parent is x
    if (depth[x] == depth[y])  depth[x]++;  //x's depth is same as y's depth,add depth

  }
}

inline bool same(int x, int y)
{
  return find(x) == find(y);
}

int main()
{
  //Test
  int n,a,b;
  init(MAXN);
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> a >> b;
    par[b] = a;
  }
  cin >> a >> b;
  cout << same(a,b);
  unite(a,b);
  cout << same(a,b);
  return 0;
}
