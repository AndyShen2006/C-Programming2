#include<bits/stdc++.h>

using namespace std;

vector<int> factors;

void factor(int n)  //No refactor
{
  for(int i=sqrt(n); i>=2; i++) {
    if(n%i==0) {
      factors.push_back(i);
    }
  }
  for(auto i : factors) {
    factors.push_front(n/i);
  }
}

int main()
{
  //This solution is not very good,Need to refactor
  
}
