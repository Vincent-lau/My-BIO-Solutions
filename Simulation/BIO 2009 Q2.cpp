//problem source: BIO 2009 Question2 :Puzzle Game
//纯粹的模拟题，好久不做，此题算是这些年来我做到的最简单的模拟题了
#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int visited[10][10];
char grid[10][10];
char oriGrid[10][10];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int nScore;
void Dfs(int r,int c,bool pFlag){
    visited[r][c]=1;
    bool nFlag=false;
    for(int k=0;k<4;++k){
        int newR=r+dir[k][0];
        int newC=c+dir[k][1];
        if(newR>=4 || newR<0 || newC>=4 || newC<0)
            continue;
        if(grid[newR][newC]==grid[r][c] &&!visited[newR][newC]){
            ++nScore;
            Dfs(newR,newC,1);
            nFlag=true;
        }
    }
    if(nFlag || pFlag)
        grid[r][c]=' ';
}
int check(){
    memset(visited,0,sizeof(visited));
    int nTotalScore=1;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j){
            nScore=1;
            if(!visited[i][j])
                Dfs(i,j,0);
      //      cout<<nScore<<' '<<i<<' '<<j<<endl;
            nTotalScore*=nScore;
        }
    if(nTotalScore==1)
        return 0;
    else
        return nTotalScore;
}
void update(){
    for(int j=0;j<4;++j){
        vector<char> v;
        for(int i=3;i>=0;--i)
            if(grid[i][j]!=' ')
                v.push_back(grid[i][j]);
        while(v.size()<4){
            v.push_back(oriGrid[3][j]);
            char tmp=oriGrid[3][j];
            for(int k=3;k>0;--k)
                oriGrid[k][j]=oriGrid[k-1][j];
            oriGrid[0][j]=tmp;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<4;++i)
            grid[i][j]=v[i];
    }
}
int main(){
    freopen("/Users/liuliu/Desktop/debug/c/data.in","r",stdin);
    //freopen("/Users/liuliu/Desktop/debug/c/data.out","w",stdout);
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            cin>>oriGrid[i][j];
    memcpy(grid,oriGrid,sizeof(oriGrid));
    int nTotalScore=0;
    int T;
    while(cin>>T){
        while(T--){
            int score=check();
            if(score==0){
                cout<<"Game Over"<<endl;
                break;
            }
            nTotalScore+=score;
    /*        for(int i=0;i<4;++i){
                for(int j=0;j<4;++j)
                    cout<<grid[i][j];
                cout<<endl;
            }*/

            update();
        //    cout<<endl;
            if(T==0)
                for(int i=0;i<4;++i){
                    for(int j=0;j<4;++j)
                        cout<<grid[i][j];
                    cout<<endl;
                }
        }
        cout<<nTotalScore<<endl<<endl;
    }
/*    nTotalScore+=check();
    cout<<endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j)
            cout<<grid[i][j];
        cout<<endl;
    }
    update();
    cout<<endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j)
            cout<<grid[i][j];
        cout<<endl;
    }
    cout<<nTotalScore<<endl;*/
    fclose(stdin);   //fclose(stdout);
    return 0;
}
