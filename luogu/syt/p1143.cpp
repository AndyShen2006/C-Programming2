#include<bits/stdc++.h>
//�ƺ��������û��itoa������ֱ�ӳ��˷�itoa��ʵ�֣������233 
using namespace std;
char* itoa(int num,char* str,int radix)
{
    char index[]="0123456789ABCDEF";
    unsigned unum;
    int i=0,j,k;
    if(radix==10&&num<0)
    {
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else unum=(unsigned)num;
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
       }while(unum);
    str[i]='\0';
    if(str[0]=='-')
        k=1;
    else
        k=0;
     
    for(j=k;j<=(i-1)/2;j++)
    {       char temp;
        temp=str[j];
        str[j]=str[i-1+k-j];
        str[i-1+k-j]=temp;
    }
    return str;
}

int main()
{
	int n,m;
	char temp[40],k[40],*tEnd;
	cin >> n >> k >> m;
	itoa(strtol(k, &tEnd, n), temp, m);
	cout << temp;
	return 0;
}
