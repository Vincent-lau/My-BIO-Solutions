//problem source: BIO 2013 Question1: Watching the clock
//简单题，求(m-n)t+24*60Y=0的解
//只要求出b/d 即 (24*60)/gcd(m-n,24*60)即可
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int Gcd(int a,int b){
	return b==0?a:Gcd(b,a%b);
}
int main(){
	freopen("data.in","r",stdin);
	int m,n;
	while(cin>>m>>n){
		m+=60,n+=60;
		int b=24*60;
		int d=Gcd(abs(m-n),b);
		int ans=b/d*m;             //这里不要忘记乘m就好了
		cout<<b/d<<endl;
		int hour=ans/60%24,minute=ans%60;
		cout<<setw(2)<<setfill('0')<<hour<<':'<<setw(2)<<setfill('0')<<minute<<endl;
	}
	fclose(stdin); //fclose(stdout);
  	return 0;
}
