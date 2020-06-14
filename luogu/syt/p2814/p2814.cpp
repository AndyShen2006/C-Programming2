#include<iostream>
#include<string>

#define MAXN 60000
#define MAXDEPTH 40

using namespace std;

int par[MAXN] = {0};
int depth[MAXDEPTH] = {0};
string key[MAXN] = {0};

void init(int n)
{
  for(int i = 0; i < n; i++) {
    par[i] = i;
    depth[i] = 0;
  }
}

int findroot(int x)
{
  if(par[x] == x) {
    return x;
  } else {
    return par[x] = findroot(par[x]);
  }
}

inline int findstr(string x, int n)
{
  for(int i=1;i<=n; i++) {
    if(key[i] == x)  return i;
  }
  return -1;
}
inline void unite(int x, int y)
{
  x = findroot(x);
  y = findroot(y);

  if(x == y)  return;

  if(depth[x] < depth[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(depth[x] == depth[y])  depth[x]++;
  }
}
int main()
{
  char s;
  string n,dad;
  int local=1;
  int pos;
  s=getchar();
  while(s != '$') {
    cin >> n;
    if(findstr(n, local+1) == -1) {  //If you cant find it in array,add new and save it
      ++local;
      key[local] = n;
    }
    pos = findstr(n, local+1);
    if(s == '#') {
      dad = n;
    } else if(s == '+') {
      par[pos] = findstr(dad, local+1);
    } else {
      cout << n << ' ' << key[findroot(pos)] << endl;
    }
    s=getchar();
  }
  return 0;
}
