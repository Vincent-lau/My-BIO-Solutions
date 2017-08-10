//problem source:BIO 2015 Question 3:Modern Art
//一道纯粹的排列计数题，给定数字求排列，alphabetical order
//之前不大会排列计数，参看了模板后才写的
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int rest[10];
inline long long fac(int x){     //long long的阶乘
	return x==0?1:x*fac(x-1);
}
long long Ways(int i,int len,int cur){   //long long的方案数
	int tmp[10];
	memcpy(tmp,rest,sizeof(rest));
	--tmp[cur];
	long long repSum=1;
	for(int k=0;k<4;++k)
		repSum*=fac(tmp[k]);
	return fac(len-i-1)/repSum;       //这里有一点数学知识，即在一个集合中，每个元素个数为a[i]，总元素个数为M
                                    //那么总排列的个数为M!/a[0]*!a[1]!*...*a[N]!
}
void GenPermutationByNum(char *permutation,int len,long long No){   //排列总长度为len,求第No个排列
	--No;
	int perInt[30];
	for(int i=0;i<len;++i){
		int j;
		for(j=0;j<4;++j){
			if(rest[j]){
				long long ways=Ways(i,len,j);
				if(ways>=No+1)
					break;
				else
					No-=ways;
			}
		}
		--rest[j];
		perInt[i]=j;            //perInt 表示所求排列的第i位选择的字母的序号
	}
	for(int i=0;i<len;++i)
		permutation[i]=perInt[i]+'A';
	permutation[len]=0;
}

int main(){
	freopen("data.in","r",stdin);
	long long n;
	int len=0;
	for(int i=0;i<4;++i){
		cin>>rest[i];
		len+=rest[i];
	}
	cin>>n;
	char permutation[30];
	GenPermutationByNum(permutation,len,n);
	cout<<permutation<<endl;
	fclose(stdin); //fclose(stdout);
  	return 0; 
}
