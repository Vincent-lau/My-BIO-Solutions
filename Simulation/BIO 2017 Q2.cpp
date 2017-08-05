//problem source:2017 BIO question 2 Dots and Boxes
//神级坑爹题。。。
//style of code not elegant due to the limited time
//pure simulation, no algorithm used
//remainder: while simulating on a board or a grid, using a single number instead of row and column might be better
//suggestion: give up this kind of question, extremely time-consuming while debugging
#include<bits/stdc++.h>
using namespace std;
char win[10][10];
int connected[40][40]; //表示任意两个编号的点是否相连，比用4-dimensional array 更好一些
int p1,m1,p2,m2,t;
bool check(int i,int j,int side){
	int r1=(i-1)/6+1;
	int c1=(i-1)%6+1;
	int r2=(j-1)/6+1;
	int c2=(j-1)%6+1;
	if(r1==r2){
		bool b1,b2,b3;
		bool upFlag,downFlag;
		b1=(i-6>0) && connected[i][i-6];
		b2=(j-6>0) && connected[j][j-6];
		b3=(i-6>0) && connected[i-6][j-6];
		upFlag=b1&& b2 && b3;

		if(upFlag){
			if(side==1)
				win[min(r1,r2)-1][min(c1,c2)]='X';
			else
				win[min(r1,r2)-1][min(c1,c2)]='O';
		}
		b1=(i+6<=36) && connected[i][i+6];
		b2=(j+6<=36) && connected[j][j+6];
		b3=(i+6<=36) && connected[i+6][j+6];
		downFlag=b1 && b2 && b3;
		if(downFlag){
			if(side==1)
				win[min(r1,r2)][min(c1,c2)]='X';
			else
				win[min(r1,r2)][min(c1,c2)]='O';
		}
		return upFlag || downFlag;
	}
	else{
		bool b1,b2,b3;
		bool lFlag,rFlag;
		b1=(i%6!=0) && connected[i][i+1];
		b2=(j%6!=0) && connected[j][j+1];
		b3=(i%6!=0) && connected[i+1][j+1];
		rFlag=b1 && b2 && b3;
		if(rFlag){
			if(side==1)
				win[min(r1,r2)][min(c1,c2)]='X';
			else
				win[min(r1,r2)][min(c1,c2)]='O';
		}
		b1=(i%6!=1) && connected[i][i-1];
		b2=(j%6!=1) && connected[j][j-1];
		b3=(i%6!=1) && connected[i-1][j-1];
		lFlag=b1 && b2 && b3;
		if(lFlag){
			if(side==1)
				win[min(r1,r2)][min(c1,c2)-1]='X';
			else
				win[min(r1,r2)][min(c1,c2)-1]='O';
		}
		return lFlag || rFlag;
	}
}
void player1(){
	int i,j;
	do{
		if(t==0)
			return;
		--t;
		p1+=m1;
		if(p1>36)
			p1-=36;
		while(true){
			if(p1-6>0 && !connected[p1][p1-6]){
				connected[p1][p1-6]=connected[p1-6][p1]=1;
				i=p1,j=p1-6;
				break;
			}
			if(p1%6!=0 && !connected[p1][p1+1]){
				connected[p1+1][p1]=connected[p1][p1+1]=1;
				i=p1,j=p1+1;
				break;
			}
			if(p1+6<=36 && !connected[p1][p1+6]){
				connected[p1][p1+6]=connected[p1+6][p1]=1;
				i=p1,j=p1+6;
				break;
			}
			if(p1%6!=1 && !connected[p1][p1-1]){
				connected[p1][p1-1]=connected[p1-1][p1]=1;
				i=p1,j=p1-1;
				break;
			}
			++p1;
			if(p1>36)
				p1-=36;
		}
	}while(check(i,j,1));
	
}
void player2(){
	int i,j;
	do{
		if(t==0)
			return;
		--t;
		p2+=m2;
		if(p2>36)
			p2-=36;
		while(true){			
			if(p2-6>0 && !connected[p2][p2-6]){
				connected[p2][p2-6]=connected[p2-6][p2]=1;
				i=p2,j=p2-6;
				break;
			}
			if(p2%6!=1 && !connected[p2][p2-1]){
				connected[p2][p2-1]=connected[p2-1][p2]=1;
				i=p2,j=p2-1;
				break;
			}
			if(p2+6<=36 && !connected[p2][p2+6]){
				connected[p2][p2+6]=connected[p2+6][p2]=1;
				i=p2,j=p2+6;
				break;
			}
			if(p2%6!=0 && !connected[p2][p2+1]){
				connected[p2+1][p2]=connected[p2][p2+1]=1;
				i=p2,j=p2+1;
				break;
			}			
			++p2;
			if(p2>36)
				p2-=36;
		}
	}while(check(i,j,2));
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin>>p1>>m1>>p2>>m2>>t){
		memset(connected,0,sizeof(connected));
		for(int i=1;i<=5;++i)
			for(int j=1;j<=5;++j)
				win[i][j]='*';
		while(t>0){
			player1();
			if(t<=0)
				break;				
			player2();
		}
		for(int i=1;i<=5;++i){
			for(int j=1;j<=5;++j)
				cout<<win[i][j]<<' ';
			cout<<endl;
		}
		cout<<endl;
	}
	fclose(stdin);   fclose(stdout);
	return 0;
}
