#include<bits/stdc++.h>

using namespace std;

#define N 8

int gQueen[N] = {-1};
int gSolutionCount = 0;

inline bool check(int row, int trypos)
{
  for (int i=0; i < row; i++) {
    int pos = gQueen[i];
    if (trypos == pos || (row-i == pos-trypos) || (row-i == trypos-pos)) {
      return false;
    }
  }
  return true;
}

void showResult()
{
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < gQueen[row]; col++) {
      cout << "0 ";
    }
    cout << "1 ";
    for (int col = gQueen[row]+1; col < N; col++) {
      cout << "0 ";
    }
    cout << endl;
  }
}

void solve()
{
  int row = 0;
  while (row >= 0) {
    ++gQueen[row];
    while (gQueen[row] < N && !check(row, gQueen[row])) {
      ++gQueen[row];
    }
    if (gQueen[row] < N && row == N-1) {
      ++gSolutionCount, showResult();
    } else if (gQueen[row] < N && row < N-1) {
      ++row;
    } else {
      gQueen[row] = -1;
      --row;
    }
  }
}

int main()
{
  solve();
  return 0;
}