//problem source:BIO 2013 Question2: Neutron
//time consumed:4.5hr+
//simulating the process of a game
//没什么好说的，纯粹的细节，BIO第二题真的是太喜欢靠细节了，我真是不擅长,代码还是非一般的长，虽说是因为我自己写得不够优雅
//做这种题还真是累啊
#include <iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
using namespace std;
int Dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char board[10][10];         //虽说可以用一维数组，但不方便判越界
int PiecePos[2][5]={{20,21,22,23,24},{0,1,2,3,4}};
int order[2][5];
int neutron_pos;
int calls=0;
void output(bool flag=false){
	if(calls++<=1 || flag){
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j)
				cout<<board[i][j];	
			cout<<endl;	
		}
		cout<<endl;
	}
}
//表示对于player side来说，在pos这个位置，要进行d方向的移动，接下来要移动的piece的位置为piecePos
//返回值：1:自己赢;0:无法移动;-1:对手赢(两种情况);2:什么都没有
int move_check(int pos,int d,int side,int piecePos=-1){ 
	int r=pos/5,c=pos%5;
	int newR=r+Dir[d][0],newC=c+Dir[d][1];
	if(newR<0 || newR>=5 || newC<0 || newC>=5 || board[newR][newC]!='.')
		return 0;
	while(true){
		newR+=Dir[d][0],newC+=Dir[d][1];
		if(newR<0 || newR>=5 || newC<0 || newC>=5 || board[newR][newC]!='.')
			break;
	}
	newR-=Dir[d][0],newC-=Dir[d][1];
	int des=newR*5+newC;
	if(side==1){
		if(des>=20 && des<25)
			return 1;
		if(des>=0 && des<5)
		 	return -1;
	}
	else{
		if(des>=0 && des<5)
			return 1;
		if(des>=20 && des<25)
			return -1;
	}
	if(piecePos!=-1){
		swap(board[r][c],board[newR][newC]);    //这里要先假装已经移动，才能判断接下来要移动的piece的情况
		int i;
		for(i=0;i<8;++i){
			int tmpR=piecePos/5+Dir[i][0];
			int tmpC=piecePos%5+Dir[i][1];
			if(tmpR>=0 && tmpR<5 && tmpC>=0 && tmpC<5 && board[tmpR][tmpC]=='.')
				break;
		}
		if(i==8){
			swap(board[r][c],board[newR][newC]);        //此处也需要换回
			return -1;
		}
		swap(board[r][c],board[newR][newC]);
	}
	return 2;
}
void Move(int pos,int d,int side,bool neutron,int pieceNum=-1){
	--side;
	int r=pos/5,c=pos%5;
	int newR=r+Dir[d][0],newC=c+Dir[d][1];
	while(true){
			newR+=Dir[d][0],newC+=Dir[d][1];
			if(board[newR][newC]!='.')
				break;
	}
	newR-=Dir[d][0],newC-=Dir[d][1];
	int des=newR*5+newC;
	swap(board[r][c],board[newR][newC]);
	if(neutron)
		neutron_pos=des;
	else
		PiecePos[side][pieceNum]=des;
}

int main(){
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int s1=0,s2=0;
	int result[8];
	neutron_pos=12;
	for(int i=0;i<2;++i)
		for(int j=0;j<5;++j){
			cin>>order[i][j];
			--order[i][j];
		}
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j){
			if(i==0)
				board[i][j]='S';
			else if(i==4)
				board[i][j]='F';
			else if(i==2 && j==2)
				board[i][j]='*';
			else board[i][j]='.';
		}
  while(true){
		int pieceNum=order[0][s1];
		s1=(s1+1)%5;
		int i;
		for(i=0;i<8;++i){
		 	result[i]=move_check(neutron_pos,i,1,PiecePos[0][pieceNum]);
			if(result[i]==1){
				Move(neutron_pos,i,1,1);
				break;
			}
		}
		if(i==8){
			for(i=0;i<8;++i){
				if(result[i]==2){
					Move(neutron_pos,i,1,1);
					break;
				}
			}
			if(i==8){
				for(i=0;i<8;++i)
					if(result[i]==-1){
						Move(neutron_pos,i,1,1);
						break;
					}
				break;
			}
		
			for(int i=0;i<8;++i)
				if(move_check(PiecePos[0][pieceNum],i,1)){
					Move(PiecePos[0][pieceNum],i,1,0,pieceNum);
					break;
				}
		}
		else
			break;        //如果赢了就不要管piece了
		output();
		pieceNum=order[1][s2];
		s2=(s2+1)%5;
		for(i=0;i<8;++i){
			result[i]=move_check(neutron_pos,i,2,PiecePos[1][pieceNum]);
			if(result[i]==1){
				Move(neutron_pos,i,2,1);
				break;
			}
		}
		if(i==8){
			for(i=0;i<8;++i){
				if(result[i]==2){
					Move(neutron_pos,i,2,1);
					break;
				}
			}
			if(i==8){
				for(i=0;i<8;++i)
					if(result[i]==-1){
						Move(neutron_pos,i,2,1);
						break;
					}	
				break;
			}
		
			for(int i=0;i<8;++i)
				if(move_check(PiecePos[1][pieceNum],i,2)){
					Move(PiecePos[1][pieceNum],i,2,0,pieceNum);
					break;
				}
		}
		else
			break;
		output();
	}
	output(1);
  fclose(stdin); //fclose(stdout);
  return 0;
}
