//problem source: BIO 2010 Question3:Juggluging
//BFS+set判重
//最后一组数据过不了:
/*   3 13
     241 181 31
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
struct Status{
    int water[3];
    int steps;
    Status(int *w,int ss){
        memset(water,0,sizeof(water));
        memcpy(water,w,sizeof(water));
        steps=ss;
    }
    Status(){}
};
int volume[3];
string convert(int *w){   //转成字符串判重，保留前导0
    char s[10][10];
    memset(s,0,sizeof(s));
    for(int i=0;i<3;++i)
        sprintf(s[i],"%03d",w[i]);
    string s1(s[0]);
    string s2(s[1]);
    string s3(s[2]);
    return s1+s2+s3;
}
queue<Status> q;
set<string> used;
int Bfs(int jugs,int goal){
    used.clear();
    int water[3]={0,0,0};
    q.push(Status(water,0));
    used.insert("000000000");
    while(!q.empty()){
        Status s=q.front();
        q.pop();
        for(int i=0;i<jugs;++i)
            if(s.water[i]==goal)
                return s.steps;
        for(int i=0;i<jugs;++i)
            cout<<s.water[i]<<' ';
        cout<<"     "<<s.steps<<endl;
        for(int i=0;i<jugs;++i){
            Status ns;
            ns=s;
            ns.water[i]=0;
            ++ns.steps;
            string tmp;
            tmp=convert(ns.water);
            if(used.find(tmp)==used.end()){
                q.push(ns);
                used.insert(tmp);
            }

            ns=s;
            ns.water[i]=volume[i];
            ++ns.steps;
            tmp=convert(ns.water);
            if(used.find(tmp)==used.end()){
                q.push(ns);
                used.insert(tmp);
            }


            for(int j=0;j<jugs;++j){
                if(i==j || s.water[j]==volume[j])
                    continue;
                ns=s;
                int left=volume[j]-s.water[j];
                if(s.water[i]>left){
                    ns.water[j]=volume[j];
                    ns.water[i]-=left;
                    ++ns.steps;
                }
                else{
                    ns.water[i]=0;
                    ns.water[j]+=s.water[i];
                    ++ns.steps;
                }
                tmp=convert(ns.water);
                if(used.find(tmp)==used.end()){
                    q.push(ns);
                    used.insert(tmp);   //在状态入队时就要设置为已经使用过，以前被坑过
                }
            }

        }
    }
    return -1;
}
int main(){
    //freopen("/Users/liuliu/Desktop/debug/c/data.in","r",stdin);
    //freopen("/Users/liuliu/Desktop/debug/c/data.out","w",stdout);
    int jugs,goal;
    cin>>jugs>>goal;
    for(int i=0;i<jugs;++i)
        cin>>volume[i];
    cout<<Bfs(jugs,goal)<<endl;
   // fclose(stdin);   //fclose(stdout);
    return 0;
}
