//dp代替记忆性递归
//排列组合用了新的方法
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int ways[40][40];
int totalWays[40];
char passwords[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
int main(){
    //freopen("/Users/liuliu/Desktop/debug/c/data.in","r",stdin);
    //freopen("/Users/liuliu/Desktop/debug/c/data.out","w",stdout);
    memset(ways,0,sizeof(ways));
    memset(totalWays,0,sizeof(totalWays));
    for(int i=0;i<36;++i)
        ways[1][i]=1;
    for(int i=2;i<=36;++i)
        for(int j=0;j<36;++j)
            for(int k=j+1;k<36;++k)
                ways[i][j]+=ways[i-1][k];
    for(int i=1;i<=36;++i)
        for(int j=0;j<36;++j)
            totalWays[i]+=ways[i][j];
    int n;
    cin>>n;
    int i,len;
    for(i=1;i<=36;++i)
        if(n>totalWays[i])
            n-=totalWays[i];
        else{
            len=i;
            break;
        }
    int pre=-1;
    int perInt[40];
    //cout<<ways[len][9]<<endl;
    for(int i=0;i<len;++i){
        int j;
        for(j=pre+1;j<36;++j)
            if(n>ways[len-i][j]){
            //    cout<<j<<' '<<ways[len-i][j]<<' '<<n<<endl;
                n-=ways[len-i][j];

            }
            else
                break;
        perInt[i]=j;
        pre=j;
    }
    char result[40];
    for(int i=0;i<len;++i)
        result[i]=passwords[perInt[i]];
    result[len]=0;
    cout<<result<<endl;
    //fclose(stdin);   fclose(stdout);
    return 0;
}
