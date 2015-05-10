#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <list>
using namespace std;

const int maxn=25000;

string dic[maxn];
int dp[17][17];
list<int> g[maxn];
int color[maxn];

bool editstep(string& lhs, string& rhs){
    int llen = lhs.length();
    int rlen = rhs.length();
    for(int i = 0; i <= 16; i ++){
        dp[i][0]=i;
        dp[0][i]=i;
    }

    for(int i = 1; i <= llen; i ++){
        for(int j = 1; j <= rlen; j ++){
            dp[i][j]=min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]+(lhs[i]==lhs[j]?0:1)));
        }
    }

    if(dp[llen][rlen]==1) return true;
    else return false;
}

struct I{
    I(int i, int s):id(i), seq(s){}
    int id, seq;
};

int DFS(int src){
    int ans = 0;
    stack<I> s;
    s.push(I(src,1));
    color[src]=1;
    while(!s.empty()){
        I tmp = s.top();
        s.pop();
        color[tmp.id]=2;
        list<int>::iterator it;
        for(it=g[tmp.id].begin(); it != g[tmp.id].end(); it ++){
            int n = *it;
            if(color[n]==0){
                color[n]=1;
                s.push(I(n, tmp.seq+1));
            }
        }
        ans=max(ans, tmp.seq);
    }
    return ans;
}

int main(){
    int cnt = 0;
    while(cin>>dic[cnt++]){
        for(int i = 0; i < cnt; i ++){
            for(int j = i + 1; j < cnt; j ++){
                if(editstep(dic[i], dic[j])) g[i].push_back(j);
            }
        }
        
        memset(color, 0, sizeof(color));

        int ans = 0;
        for(int i = 0; i < cnt; i ++){
            if(color[i] == 0){
                ans = max(ans, DFS(i));                
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
