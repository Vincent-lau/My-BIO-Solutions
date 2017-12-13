//problem source: BIO 2017 Question3: Mystery Parcel
//好难一题，不算特别变态，要两次dp，第二次是关键
//代码量少，但是需要很多思考，尤其是在状态转移和初始条件的设定上
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int ways[25+5][25+5][10+5];   //ways[i][j][k]表示用i件<=k的物品凑j的方案数
int dp[5+5][25+5];             //dp[i][j]表示i个包裹，用掉正好j件物品的方案数
int main(){
    memset(ways,0,sizeof(ways));
    int parcel,maxK,num,weight;
    cin>>parcel>>maxK>>num>>weight;
    for(int k=0;k<=maxK;++k)
        ways[0][0][k]=1;
    for(int i=1;i<=num;++i)
        for(int j=1;j<=weight;++j)
            for(int k=1;k<=maxK;++k){
                ways[i][j][k]=ways[i][j][k-1];
                if(j>=k)
                    ways[i][j][k]+=ways[i-1][j-k][k];

            }

    memset(dp,0,sizeof(dp));
    dp[0][0]=1;     //初始条件中不能把dp[1....p][0]设为1，因为根据题意，在任何一个包裹中都至少要有一件物品
    for(int i=1;i<=parcel;++i)
        for(int j=1;j<=num;++j)
            for(int k=1;k<=j;++k)
                dp[i][j]+=dp[i-1][j-k]*ways[k][weight][maxK];

    cout<<dp[parcel][num]<<endl;
    return 0;
}
