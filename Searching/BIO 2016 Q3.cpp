//problem source:BIO 2016 Question3: Prime Connections
//main process:Bfs+linear prime number filtration
//Real test case didn't have upper limit greater than 1e6,so Bfs will be enough. But if the range is greater,dBfs might be used
#include <iostream>
#include <cstdio>
#include<cstring>
#include <algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
using namespace std;
struct Status{
	int num;
	int steps;
	Status(int n,int s):num(n),steps(s){}
	Status(){}
};
int l;
bool isPrime[20000000];
bool used[20000000];   //this is a lit bit waste of memory, not sure if set can be used
vector<int> primes;
void getPrime(int N){
	memset(isPrime,true,sizeof(isPrime));
	isPrime[1]=0;
	primes.clear();
	for(int i=2;i<=N;++i){
		if(isPrime[i])
			primes.push_back(i);
		for(unsigned int j=0;j<primes.size();++j){
			if(i*primes[j]<=N)
				isPrime[i*primes[j]]=0;
			else
				break;
			if(i%primes[j]==0)
				break;
		}
	}
}
int Bfs(int startNum,int endNum){
	queue<Status> q;
	memset(used,0,sizeof(used));
	q.push(Status(startNum,1));
	used[startNum]=1;
	while(!q.empty()){
		Status s=q.front();
		q.pop();
		if(s.num==endNum)
			return s.steps;
		int L=0;
		while(true){
			int Inc=s.num+(1<<L);
			if(Inc <=l && isPrime[Inc] && !used[Inc]){
				q.push(Status(Inc,s.steps+1));
				used[Inc]=1;
			}
			int Dec=s.num-(1<<L);				//both increase and decrease should be considered
			if(Dec>1 && isPrime[Dec] && !used[Dec]){
				q.push(Status(Dec,s.steps+1));
				used[Inc]=1;
			}
			if(Inc>l && Dec<1)
				break;
			++L;
		}
	}
	return -1;
}
int main(){
	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
   	getPrime(1<<24);
   	int s,e;
   	while(cin>>l>>s>>e)
   		cout<<Bfs(s,e)<<endl;
    fclose(stdin); //fclose(stdout);
  	return 0;
    
}
