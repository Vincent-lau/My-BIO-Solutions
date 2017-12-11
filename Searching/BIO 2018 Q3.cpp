//problem source: BIO 2018 Question3:Serial Numbers
//纯粹的广搜，很简单一题，考试时候为了正确率做的很慢
#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
    char s[15];
    int steps;
};
queue<Node> q;
set<int> used;
int Bfs(char oriS[],int d){
    used.clear();
    while(!q.empty())
        q.pop();
    Node nd;
    memcpy(nd.s,oriS,(d+1)*sizeof(char));   //这里要注意一下在函数传参之后最好不要用sizeof()，原因不明。 
                                            //还有一点就是对于一个char数组来说，size总是总字符数+1
    nd.steps=0;
    q.push(nd);
    used.insert(atoi(oriS));
    while(!q.empty()){
        nd=q.front();
    //    cout<<nd.s<<' '<<nd.steps<<endl;
        for(int i=0;i<d-1;++i){
            int large=max(nd.s[i],nd.s[i+1]);
            int small=min(nd.s[i],nd.s[i+1]);
            int left=-1,right=-1;
            if(i>0)
                left=nd.s[i-1];
            if(i<d-2)
                right=nd.s[i+2];
            bool flag=false;
            if(left!=-1)
                flag|=(left>small && left<large);
            if(right!=-1)
                flag|=(right>small && right<large);
            if(flag){
                Node newNd=nd;
                swap(newNd.s[i],newNd.s[i+1]);

                ++newNd.steps;
                int intSta=atoi(newNd.s);
                if(used.find(intSta)==used.end()){
                    used.insert(intSta);
                    q.push(newNd);
                }
            }
        }

        q.pop();
    }
    return nd.steps;
}
int main(){
    //freopen("/Users/liuliu/Desktop/debug/c/data.in","r",stdin);
    //freopen("/Users/liuliu/Desktop/debug/c/data.out","w",stdout);
    char oriS[15];
    int d;
    cin>>d>>oriS;
    cout<<Bfs(oriS,d)<<endl;
    //cout<<*lower_bound(b,b+3,20)<<endl;
    //fclose(stdin);   //fclose(stdout);
    return 0;
}
