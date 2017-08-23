//problem source:BIO 2014 question2 Loops
//不得不吐槽这道题的繁琐了，没有什么算法上的难度，纯粹拼细节，做了我将近一个下午
//if better solution is available,please tell me
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
int layout[40];
int N;
int change[4];
bool scored[40];     //此处用来防止重复计算得分
bool connected(int p1,int p2,bool solid){   //最繁琐的就是判断是否与周围的格子相连接了，写的我半死，也不知道有什么好的方法
	if(solid){      //还要考虑实线虚线两种，用solid来区分
		switch(layout[p1]){
			case 1:{
				bool b1=p2-p1==N && (layout[p2]==3 || layout[p2]==4 || layout[p2]==1);
				bool b2=p2-p1==-N && (layout[p2]==5 || layout[p2]==6 || layout[p2]==1);
				return b1||b2;
			}
			case 2:{
				bool b1= p2-p1==1 && (layout[p2]==6 || layout[p2]==3 || layout[p2]==2);
				bool b2= p2-p1==-1 && (layout[p2]==5 || layout[p2]==4 || layout[p2]==2);
				return b1||b2;
			}
			case 3:{
				bool b1= p2-p1==-1 && (layout[p2]==4 || layout[p2]==2 || layout[p2]==5);
				bool b2= p2-p1==-N && (layout[p2]==1 || layout[p2]==6 || layout[p2]==5);
				return b1||b2;
			}
			case 4:{
				bool b1=p2-p1==1 && (layout[p2]==2 || layout[p2]==3 || layout[p2]==6);
				bool b2=p2-p1==-N && (layout[p2]==1 || layout[p2]==5 || layout[p2]==6);
				return b1||b2;
			}
			case 5:{
				bool b1=p2-p1==N && (layout[p2]==1 || layout[p2]==4 || layout[p2]==3);
				bool b2=p2-p1==1 && (layout[p2]==6 || layout[p2]==2 || layout[p2]==3);
				return b1||b2;
			}
			case 6:{
				bool b1=p2-p1==N && (layout[p2]==1 || layout[p2]==3 || layout[p2]==4);
				bool b2=p2-p1==-1 && (layout[p2]==5 || layout[p2]==2 || layout[p2]==4);
				return b1||b2;
			}
				
		}
	}
	else{
		switch(layout[p1]){
			case 1:{
				bool b1= p2-p1==1 && (layout[p2]==4 || layout[p2]==5 || layout[p2]==1);
				bool b2= p2-p1==-1 && (layout[p2]==3 || layout[p2]==6 || layout[p2]==1);
				return b1||b2;
			}
			case 2:{
				bool b1=p2-p1==N && (layout[p2]==5 || layout[p2]==6 || layout[p2]==2);
				bool b2=p2-p1==-N && (layout[p2]==3 || layout[p2]==4 || layout[p2]==2);
				return b1||b2;
			}
			case 3:{
				bool b1=p2-p1==N && (layout[p2]==2 || layout[p2]==6 || layout[p2]==5);
				bool b2=p2-p1==1 && (layout[p2]==4 || layout[p2]==1 || layout[p2]==5);
				return b1||b2;
			}
			case 4:{
				bool b1=p2-p1==N && (layout[p2]==5 || layout[p2]==2 || layout[p2]==6);
				bool b2=p2-p1==-1 && (layout[p2]==1 || layout[p2]==3 || layout[p2]==6);
				return b1||b2;
			}
			case 5:{
				bool b1= p2-p1==-1 && (layout[p2]==6 || layout[p2]==1 || layout[p2]==3);
				bool b2= p2-p1==-N && (layout[p2]==2 || layout[p2]==4 || layout[p2]==3);
				return b1||b2;
			}
			case 6:{
				bool b1=p2-p1==1 && (layout[p2]==1 || layout[p2]==5 || layout[p2]==4);
				bool b2=p2-p1==-N && (layout[p2]==2 || layout[p2]==3 || layout[p2]==4);
				return b1||b2;
			}
				
		}
	}
	return false;
}
int score(int pos,bool solid){   //表示在pos这个位置solid方所能获得的分数，已去重
	bool visited[40];
	memset(visited,0,sizeof(visited));
	deque<int> dq;      //用栈来进行Dfs为了方便记录路径从而避免重复计算
	dq.push_back(pos);
	visited[pos]=1;
	while(!dq.empty()){
		int s=dq.back();
		int i;
		for(i=0;i<4;++i){
			int newPos=s+change[i];
			if(newPos>=N*N || newPos<0)
				continue;
			if(connected(s,newPos,solid) && dq[0]==newPos && dq[dq.size()-2]!=newPos){   //this step should not only consider the loop                                               
				int tmp=dq.size();                                                            //but also avoid going back to the previous step 
				while(!dq.empty()){
					scored[dq.back()]=1;
					dq.pop_back();
				}
				return tmp;
			}
			if(connected(s,newPos,solid) && !visited[newPos] && !scored[newPos]){				
				dq.push_back(newPos);
				visited[newPos]=1;
				break;
			}
		}
		if(i>=4)    //如果找不到，则回溯
			dq.pop_back();
		
	}
	return 0;
}

int main(){
//	freopen("data.in","r",stdin);
	cin>>N;
	change[0]=1,change[1]=-1,change[2]=N,change[3]=-N;
	for(int i=0;i<N*N;++i)
		cin>>layout[i];
	int s1=0,s2=0;
	memset(scored,0,sizeof(scored));
	for(int i=0;i<N*N;++i)
		s1+=score(i,1);
	memset(scored,0,sizeof(scored));
	for(int i=0;i<N*N;++i)
		s2+=score(i,0);
	cout<<s1<<' '<<s2<<endl;
	//fclose(stdin); //fclose(stdout);
  	return 0; 
}
