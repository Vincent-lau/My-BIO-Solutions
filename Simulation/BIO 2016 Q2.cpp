//problem source:BIO 2016 Question2 :Migration
//pure simulation
//在用数字对位置进行模拟的时候，如果是从零开始，则一开始就应当将位置--
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
struct Pos{
	int r,c;
	Pos(int rr,int cc):r(rr),c(cc){}
	Pos(){}
};
int land[110][110];
int convert(int p,char cmd){
	if(cmd=='r')
		return p/5+50;
	else
		return p%5+50;
}
int P,S,N;
int seq[10];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	freopen("data.in","r",stdin);
	while(cin>>P>>S>>N){
      --P;    //这里就应当将初始位置--
    memset(land,0,sizeof(land));
    for(int i=0;i<S;++i)
      cin>>seq[i];
    int j=0;
    while(N--){
      int r=convert(P,'r');
      int c=convert(P,'c');
      if(++land[r][c]>=4){
        queue<Pos> q;
        q.push(Pos(r,c));
        while(!q.empty()){
          Pos s;
          do{
            s=q.front();
            q.pop();
          }while(land[s.r][s.c]<4 && !q.empty());
          if(land[s.r][s.c]>=4){     //这里要判断当前人数是否大于4，因为可能是在 q.empty()而land[s.r][s.c]<4的时候跳出
            land[s.r][s.c]-=4;
            for(int i=0;i<4;++i){
              int newR=s.r+dir[i][0];
              int newC=s.c+dir[i][1];
              if(++land[newR][newC]>=4)
                q.push(Pos(newR,newC));
            }
          }
        }
      }
      P=(P+seq[j%S])%25;
      ++j;
	  }
	
    for(int i=50;i<55;++i){
      for(int k=50;k<55;++k)
        cout<<land[i][k]<<' ';
      cout<<endl;
    }
    cout<<endl;
	}
	fclose(stdin); //fclose(stdout);
  return 0; 
}
