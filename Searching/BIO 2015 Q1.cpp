//Problem source:BIO 2015 Q1: Block Palindromes
//main process: recursion or dfs
//lots of details that can be confusing 
//对递归的理解还是很浅薄啊
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<string>
using namespace std;
bool check(int l,int r,int i,int j,char *s){  //此处一定要设置四个参数，分别代表边界与当前指针的位置，类似于Merge sort & Quick sort
	int p=l;
	int q=j;
	while(p<=i && q<=r)
		if(s[p++]!=s[q++])
			return false;
	return true;
}
int dfs(int i,int j,char *s){
	if(i-j>1)
		return 0;
	if(i-j==1)   //此处是为了解决偶数的情况，形如XX
		return 1;
	int ways=1;   //表示当前指针内部整个括在一起可以看成是一种方案
	int ii=i,jj=j;   //此处也类似于快排中 i=s,j=e的写法，经常犯错
	while(ii<=jj){
		if(check(i,j,ii,jj,s))
			ways+=dfs(ii+1,jj-1,s);
		++ii,--jj;
	}
	return ways;
}
int main(){
	freopen("data.in","r",stdin);
	char s[20];
	int L,R;
	while(cin>>s){
		L=0,R=strlen(s)-1;
		cout<<dfs(L,R,s)-1<<endl;
	}
	fclose(stdin); //fclose(stdout);
  	return 0; 
}
