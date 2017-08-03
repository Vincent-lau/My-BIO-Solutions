//problem link:http://poj.org/problem?id=2689
//main inspiration:线性筛出sqrt(u)内所有素数，再用这些素数筛所求范围内的素数
//problem feature:range of query smaller than 1e6
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
bool isPrime[1000000+10];
vector<int> prime;
void getPrime(){ //线性筛
	long long INF=2147483647;
	int n=sqrt(INF)+1;
	memset(isPrime,true,sizeof(isPrime));
	isPrime[1]=0;
	for(int i=2;i<=n;++i){
		if(isPrime[i])
			prime.push_back(i);
		for(unsigned int j=0;j<prime.size();++j){
			long long p=prime[j];
			if(p*(long long)i>n)
				break;
			isPrime[p*i]=0;
			if(i%p==0)
				break;
		}
	}
}
void delete_composite(int L, int U){  //用得到的素数去筛给定范围的素数
	memset(isPrime,true,sizeof(isPrime));
	for(unsigned int i=0;i<prime.size();++i){
		long long n=L/prime[i];
		while(n*prime[i]<L || n<=1)
			++n;
		for(long long j=n*prime[i];j<=U;j+=prime[i])
			isPrime[j-L]=0;                               //j-L 来减小空间需求    类似于建立一个简单的映射      
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out","w",stdout);
	prime.clear();
	getPrime();
	int L,U;
	while(cin>>L>>U){
    delete_composite(L,U);
    int d1=0,d2=0,c1=0,c2=0;
    int nStartNo=0;
    bool flag=true;
    int minDist=1<<30,dist=0,maxDist=-1;
    for(long long i=L;i<=U;++i){
      if(i==1)
        continue;    //避免1的情况影响答案
      if(isPrime[i-L]){

        if(flag){
          d1=d2=i;
          c1=c2=i;
          flag=false;
        }
        else{
          if(minDist>dist){
            minDist=dist;
            c1=nStartNo;
            c2=i;
          }
          if(maxDist<dist){
            maxDist=dist;
            d1=nStartNo;
            d2=i;
          }
        }
        nStartNo=i;
        dist=0;
      }
      else
        ++dist;
    }
    if(c1==c2 || d1==d2)
      cout<<"There are no adjacent primes.";
    else
      cout<<c1<<','<<c2<<" are closest, "<<d1<<','<<d2<<" are most distant.";
    cout<<endl;
	}
	//cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
	//fclose(stdin); // fclose(stdout);
	return 0;
}
