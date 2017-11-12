//problem source: BIO 2008 question3
//太简单了，不说什么了
#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
    string status;
    int steps;
    Node(string ss,int st):status(ss),steps(st){}
    Node(){}
};
queue<Node> q;
set<string> used;
int Bfs(string oriS){
    used.clear();
    q.push(Node(oriS,0));
    used.insert(oriS);
    while(!q.empty()){
        Node s=q.front();
        q.pop();
        if(s.status=="1234567")
            return s.steps;
        char tmp;
        string ns;
        tmp=s.status[0];
        ns=s.status;
        for(int i=0;i<3;++i)
            ns[i]=s.status[i+1];
        ns[3]=tmp;
        if(used.find(ns)==used.end()){
            q.push(Node(ns,s.steps+1));
            used.insert(ns);
        }
        tmp=s.status[6];
        ns=s.status;
        for(int i=6;i>3;--i)
            ns[i]=s.status[i-1];
        ns[3]=tmp;
        if(used.find(ns)==used.end()){
            q.push(Node(ns,s.steps+1));
            used.insert(ns);
        }
        tmp=s.status[3];
        ns=s.status;
        for(int i=3;i>0;--i)
            ns[i]=s.status[i-1];
        ns[0]=tmp;
        if(used.find(ns)==used.end()){
            q.push(Node(ns,s.steps+1));
            used.insert(ns);
        }
        tmp=s.status[3];
        ns=s.status;
        for(int i=3;i<6;++i)
            ns[i]=s.status[i+1];
        ns[6]=tmp;
        if(used.find(ns)==used.end()){
            q.push(Node(ns,s.steps+1));
            used.insert(ns);
        }
    }
    return 1<<30;
}
int main(){
    //freopen("/Users/liuliu/Desktop/debug/c/data.in","r",stdin);
    //freopen("/Users/liuliu/Desktop/debug/c/data.out","w",stdout);
    string oriS;
    cin>>oriS;
    cout<<Bfs(oriS)<<endl;
    //fclose(stdin);   //fclose(stdout);
    return 0;
}
