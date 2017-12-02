//problem source: BIO 2006 Drats
//真是题目越靠前越简单了
//这更像是一道dp题，有一个特判要注意一下，其他没什么
#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ways[210][10];
int main(){
    memset(ways,0,sizeof(ways));
    int s,d;
    cin>>s>>d;
    for(int i=1;i<=20;++i)
        ways[i][1]=1;

    for(int n=1;n<=s;++n)
        for(int i=2;i<=d;++i)
            for(int j=1;j<=20 && j<=n;++j)
                ways[n][i]+=ways[n-j][i-1];
    int ans=0;
    if(d==1 && s<=40 && s%2==0)    //就是这里要特判
        ans=1;
    else
        for(int i=2;i<=40 && i<=s;i+=2)
            ans+=ways[s-i][d-1];
    cout<<ans<<endl;
    return 0;
}
