#include<bits/stdc++.h>

using namespace std;

int main()
{
	/*
	string text,pattern;
	cin >> text >> pattern;
	int i=0,j,ans=0;
	for(; i<text.size()-pattern.size(); i++) {
		for(j=0; j<pattern.size(); j++) {	
			if(text[i+j] != pattern[j]){
				//printf("text[%d]:%s != pattern[%d]:%s\n",i,&text[i],j,&pattern[j]);
				//cout << "text" << i << ":" << text[i] <<"!=" << "pattern" << ":" << pattern[j] << j << endl;
				break;
			}
		}
		if(j==pattern.size()){
			ans++;
			cout << i << endl;
		}
	}
	cout << ans;
	*/
	freopen("KMP.in","r",stdin);
	//freopen("KMP.out","rw",stdout);
	//string text,pattern;
	int lps[1000];
	string pattern;
	//cin >> text >> pattern;
	cin >> pattern;
	int n=text.size(),m=pattern.size();
	int s=0,j=0,ans=0;
	//KMP Prepare
	
	//Main
	while(s<n-m) {
		cout << s << " " << j << endl;
		if(text[s] == pattern[j]) {
			s++;
			j++;
		}else{
			s-=j-1;
			j=0;
		}
		if(j==pattern.size()-1) {
			s-=j-1;
			j=0;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
