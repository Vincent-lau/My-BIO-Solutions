//problem source: BIO 2009 Question3:Child's play
//如此简单的一题，竟然被自己坑了两回
//首先找个规律，然后类似于排列计数的原理就over了
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
long long ways[40];
int main(){
    //freopen("/Users/liuliu/Desktop/debug/c/data.in","r",stdin);
    //freopen("/Users/liuliu/Desktop/debug/c/data.out","w",stdout);
    memset(ways,0,sizeof(ways));
    int s,n;
    ways[0]=ways[1]=1;
    for(int i=2;i<=32;++i)
        for(int j=i-1;i-j<10 && j>=0;--j)  //这里很重要，因为block只有1-9的数字
            ways[i]+=ways[j];
    while(cin>>s>>n){
        while(s>0)
            for(int i=1;i<=s;++i){
                if(n-ways[s-i]>0)
                    n-=ways[s-i];
                else{
                    cout<<i<<' ';
                    s-=i;
                    break;
                }
            }

        cout<<endl;
    }

    //fclose(stdin);   //fclose(stdout);
    return 0;
}
