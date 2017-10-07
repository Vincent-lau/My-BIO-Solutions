//problem source: BIO 2011 Question3 Upside-Down
//挺进单的类似排列计数的题目,在problem3中算是很简单的题
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long base=1;
    int nCount=1;
    long long n;
    cin>>n;
    while(true){   //这里可以有更快的公式，懒得去找了
        if(nCount%2==0)
            base*=9;
        if(n-base>0)
            n-=base;
        else
            break;
        ++nCount;
    }
    bool flag=false;
    if(nCount%2!=0){
        --nCount;
        flag=true;
    }
    int num[20];
    for(int i=0;i<nCount/2;++i){
        int base=pow(9,nCount/2-i-1);
        int nTimes=n/base;
        n%=base;
        if(n==0){
            num[i]=nTimes;
            n=base;
        }
        else
            num[i]=nTimes+1;
    }

    if(flag){
        ++nCount;
        for(int i=0;i<nCount/2;++i)
            cout<<num[i];
        cout<<5;
        for(int i=nCount/2+1;i<nCount;++i)
            cout<<10-num[nCount-1-i];

    }
    else{
        for(int i=0;i<nCount/2;++i)
            cout<<num[i];
        for(int i=nCount/2;i<nCount;++i)
            cout<<10-num[nCount-1-i];

    }
    cout<<endl;
    return 0;
}
