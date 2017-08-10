//Problem source:BIO 2015 Q2:Battleships
//simulation problem, easy problem,but mistaking x coordinate for y coordinate takes a long time to correct
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int board[20][20];
int ship[]={4,3,3,2,2,2,1,1,1,1};
bool check(int r,int c,char cmd,int num){
	if(cmd=='H'){
		if(c+num-1>9)
			return false;
		for(int i=r-1;i<=r+1;++i)
			for(int j=c-1;j<=c+num;++j){
				if(i<0 || i>9 || j<0 || j>9)
					continue;
				if(board[i][j])
					return false;
			}
	}
	else{
		if(r+num-1>9)
			return false;
		for(int i=r-1;i<=r+num;++i)
			for(int j=c-1;j<=c+1;++j){
				if(i<0 || i>9 || j<0 || j>9)
					continue;
				if(board[i][j])
					return false;
			}
	}
	return true;
}
void place(int r,int c,char cmd,int num){
	if(cmd=='H')
		for(int i=0;i<num;++i)
			board[r][c+i]=1;
	else
		for(int i=0;i<num;++i)
			board[r+i][c]=1;
}
int main(){
	freopen("data.in","r",stdin);
	int a,c,m,r;
	cin>>a>>c>>m;
	memset(board,0,sizeof(board));
	r=0;
	int size=sizeof(ship)/sizeof(int);
	for(int k=0;k<size;++k){
		while(true){
			r=(a*r+c)%m;
			int y=r%10;           //此处就是x,y坐标出错的地方，平时习惯将r作为横坐标，其实际应为纵坐标
			int x=r/10%10;
			r=(a*r+c)%m;
			if(r&1){
				if(check(x,y,'V',ship[k])){
					place(x,y,'V',ship[k]);
					cout<<y<<' '<<x<<' '<<'V'<<endl;
					break;
				}
			}
			else{
				if(check(x,y,'H',ship[k])){
					place(x,y,'H',ship[k]);
					cout<<y<<' '<<x<<' '<<'H'<<endl;
					break;
				}
			}
		}
	}
/*	for(int i=9;i>=0;--i){
		for(int j=0;j<=9;++j)
			cout<<board[i][j]<<' ';
		cout<<endl;
	}*/

	fclose(stdin); //fclose(stdout);
  	return 0; 
}
