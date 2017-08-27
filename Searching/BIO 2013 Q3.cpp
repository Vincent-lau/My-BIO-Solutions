//problem source BIO 2013 Question3: Unlock
//easiest problem I have encountered in the BIO problems I have done so far
//just searching
//time used: 2hr
/* Sample run:
    mnoqRTwxy
	RST
*/
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
int oriLights[10][10];
int lights[10][10];
int s[10];
int result[10][10];
int dir[4][2]={{0,-1},{0,0},{0,1},{1,0}};
bool Dfs(int depth){     //this is the process of enumerating
    if(depth==5){
        memcpy(lights,oriLights,sizeof(oriLights));
        memcpy(result[0],s,sizeof(s));
        for(int j=0;j<5;++j)
            for(int k=0;k<4;++k){
                int newR=0+dir[k][0];
                int newC=j+dir[k][1];
                if(newR<0 || newR>=5 || newC<0 || newC>=5)
                    continue;
                (lights[newR][newC]+=s[j])%=3;
            }
        for(int i=1;i<5;++i){
            for(int j=0;j<5;++j){
                result[i][j]=(3-lights[i-1][j])%3;
                for(int k=0;k<4;++k){
                    int newR=i+dir[k][0];
                    int newC=j+dir[k][1];
                    if(newR<0 || newR>=5 || newC<0 || newC>=5)
                        continue;
                    (lights[newR][newC]+=result[i][j])%=3;
                }
            }
        }
        for(int i=0;i<5;++i)
            if(lights[4][i]!=0)
                return false;
        return true;
    }
    for(int i=0;i<3;++i){
        s[depth]=i;
        if(Dfs(depth+1))
            return true;
    }
    return false;
}
int main(){
    freopen("/Users/liuliu/Desktop/c++/c/data.in","r",stdin);
    string status;
    while(cin>>status){
    int nCount=0;
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j){
            char lowerCh=i*5+j+'a';
            char upperCh=i*5+j+'A';
            if(nCount<status.length() && status[nCount]==lowerCh){
                ++nCount;
                oriLights[i][j]=1;
            }
            else if(nCount<status.length() && status[nCount]==upperCh){
                ++nCount;
                oriLights[i][j]=2;
            }
            else
                oriLights[i][j]=0;
        }
    if(Dfs(0)){
        for(int i=0;i<5;++i)
            for(int j=0;j<5;++j){
                char ch=i*5+j;
                if(result[i][j]==1)
                    cout<<(char)(ch+'a');
                else if(result[i][j]==2)
                    cout<<(char)(ch+'A');
            }
        cout<<endl;

    }
    else
        cout<<"IMPOSSIBLE"<<endl;
    
    }
    fclose(stdin);
    return 0;
}
