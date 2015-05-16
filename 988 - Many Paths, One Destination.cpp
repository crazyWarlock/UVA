#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;

const int maxn=15000;

list<int> g[maxn];
int color[maxn];
int _time;
int dp[maxn];
struct P{
    int id, fin;
}p[maxn];

bool cmp(const P& lhs, const P& rhs){
    return lhs.fin>rhs.fin;
}

void DFS_Visit(int src){
    _time ++;
    list<int>::iterator it;
    for(it = g[src].begin(); it != g[src].end(); it ++){
        if(color[*it] == 0){
            color[*it]=1;
            DFS_Visit(*it);
        }
    }
    color[src]=2;
    _time ++;
    p[src].fin=_time;
}

void DFS(int n){
    memset(color, 0, sizeof(color));
    _time=0;

    for(int i = 0; i <= n; i ++){
        p[i].id=i;
        if(color[i] == 0){
            color[i]=1;
            DFS_Visit(i);
        }
    }
}


int main(){
    int n, k, t=0;

    while(cin>>n){
		if(t != 0) cout<<endl;
		t ++;

		for(int i = 0; i <= n; i ++) g[i].clear();

		for(int i = 0; i < n; i ++){
			cin>>k;
			if(k == 0){
				g[i].push_back(n);
				continue;
			}
			int d;
			for(int j = 0; j < k; j ++){
				cin>>d;
				g[i].push_back(d);
			}
		}
		
		/*
		for(int i = 0; i <= n; i ++){
			g[i].sort();
			g[i].unique();
		}
		*/

		DFS(n);
		sort(p, p + n + 1, cmp);

		memset(dp, 0, sizeof(dp));
		dp[p[0].id]=1;
		list<int>::iterator it;
		for(int i = 0; i <= n; i ++){
			for(it=g[p[i].id].begin(); it != g[p[i].id].end(); it ++){
				dp[*it] += dp[p[i].id];
			}
		}
		cout<<dp[n]<<endl;
    }
    return 0;
}