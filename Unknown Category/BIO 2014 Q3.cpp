//problem source: BIO 2014 Question 3:Increasing passwords
/*Sample run:
  in:37
  out:AB   
*/
//main process:dp+permutation
//感想：挺简单一题，我做了好久，主要是一个递归不会转dp搞了好久，最后还是写了个记忆递归,发现BIO特别喜欢考与字母升降序有关的东西
#include<bits/stdc++.h>
using namespace std;
long long dp[40][40];   //dp[depth][pre]表示depth个字母，depth-1个字母选取了pre这个字符
int result[40];
char passwords[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
long long Dfs(int depth,int pre){   //this is where I struggle most with because I can't think of a way using dp tp do this
	if(dp[depth][pre]!=-1)
		return dp[depth][pre];
	if(depth==0)
		return dp[depth][pre]=1;
	long long sum=0;
	for(int i=pre+1;i<=36;++i)
		sum+=Dfs(depth-1,i);
	return dp[depth][pre]=sum;
}

int main(){
	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=36;++i)
		Dfs(i,0);
	int n;
	while(cin>>n){
		int i;
		for(i=1;i<=36;++i){
			if(n>dp[i][0])
				n-=dp[i][0];
			else
				break;
		}
		int ii=i, j=1,k=0;
		while(ii>1 && j<=36){
			if(n>dp[ii-1][j])
				n-=dp[ii-1][j];
			else{
				result[k++]=j;
				--ii;
			}
			++j;
		}
		result[k++]=j-1+n;      //not to forget the last password letter
		for(int i=0;i<k;++i)
			cout<<(char)(passwords[result[i]-1]);
		cout<<endl;
	}
	fclose(stdin); // fclose(stdin);
	return 0;
}
