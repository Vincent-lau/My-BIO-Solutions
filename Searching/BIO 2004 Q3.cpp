//problem source: BIO 2004 Q3: Morse Code
//很有意思的一道动归题，dp[i][j]表示i个morse code组成长度为j的letter的方案数
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int dp[50][15];
bool valid[50][50];
string morse,letters;
const char* table1[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
vector<string> Table;
void convert(){    //letters to morse
    Table=vector<string>(table1,table1+26);
    morse.clear();
    for(int i=0;letters[i];++i)
        morse+=(Table[letters[i]-'a']);
}

int main(){
    memset(valid,0,sizeof(valid));
    memset(dp,0,sizeof(dp));
    letters="njg";
    cin>>letters;
    convert();
    int len1=morse.size();
    int len2=letters.size();
    for(int i=0;i<len1;++i){
        string tmp;
        tmp.clear();
        for(int j=i;j<i+4 && j<len1;++j){
            tmp.push_back(morse[j]);
            valid[i][j]=(find(Table.begin(),Table.end(),tmp)!=Table.end());
        }
    }
    for(int i=1;i<=4;++i)
        dp[i][1]=valid[0][i-1];
    for(int i=2;i<=len1;++i)
        for(int j=2;j<=len2;++j)
            for(int k=1;k<=4;++k)       //这里要注意下k表示的是要去掉的长度，所以是可以取到4的
                if(i-k>0 && valid[i-k][i-1])    //这里要注意的是从（i-k-1+1）到i-1
                    dp[i][j]+=dp[i-k][j-1];
    cout<<dp[len1][len2]<<endl;
    return 0;
}
