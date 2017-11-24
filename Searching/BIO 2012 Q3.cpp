//problem source BIO 2012 Question 3: Number Ladder
//pure BFS incredibly easy
//Build a graph with every two numbers between 0-999. An edge will be added if a transformation within five steps is possible.
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
struct Node{
    int x;
    int steps;
    Node(int xx,int s):x(xx),steps(s){}
    Node(){}

};
string letters[1100];
int G[1100][1100];
int H(string ns,string goalStatus){
    int i=0,j=0;
    int repeat=0;
    while(i<ns.length() && j<goalStatus.length()){
        if(ns[i]==goalStatus[j]){
            ++i,++j;
            ++repeat;
        }
        else if(ns[i]>goalStatus[j])
            ++j;
        else
            ++i;
    }
    return (int)goalStatus.length()-repeat+(int)ns.length()-repeat;
}
string convert(int i){
    switch(i){
        case 0:
            return "ZERO";
        case 1:
            return "ONE";
        case 2:
            return "TWO";
        case 3:
            return "THREE";
        case 4:
            return "FOUR";
        case 5:
            return "FIVE";
        case 6:
            return "SIX";
        case 7:
            return "SEVEN";
        case 8:
            return "EIGHT";
        case 9:
            return "NINE";
    }
    return " ";
}
queue<Node> q;
int visited[1100];
int Bfs(int s,int f){
    memset(visited,0,sizeof(visited));
    while(!q.empty())
        q.pop();
    q.push(Node(s,0));
    visited[s]=1;
    Node nd;
    while(!q.empty()){
        nd=q.front();
        if(nd.x==f)
            return nd.steps;
        for(int i=0;i<1000;++i)
            if(G[nd.x][i] && !visited[i]){
                q.push(Node(i,nd.steps+1));
                visited[i]=1;
            }
        q.pop();
    }
    return nd.steps;
}
int main(){
    memset(G,0,sizeof(G));

    for(int i=0;i<1000;++i){
        string s;
        int num=i;
        do{
            s+=convert(num%10);
            num/=10;
        }while(num!=0);
        sort(s.begin(),s.end());
        letters[i]=s;
    }
    for(int i=0;i<1000;++i)
        for(int j=i+1;j<1000;++j)
            if(H(letters[i],letters[j])<6)
                G[i][j]=G[j][i]=1;
    int s,f;
    while(cin>>s>>f)
        cout<<Bfs(s,f)<<endl;
    return 0;
}
