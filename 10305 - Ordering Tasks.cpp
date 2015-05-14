#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;

const int maxn=110;

list<int> g[maxn];
int color[maxn];
int _time;
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

    for(int i = 1; i <= n; i ++){
        p[i].id=i;
        if(color[i] == 0){
            color[i]=1;
            DFS_Visit(i);
        }
    }
}


int main(){
    int m, n, a, b;

    while(cin>>n>>m){
		if(m == 0 && n == 0) break;
		for(int i = 1; i <= n; i ++) g[i].clear();

		for(int i = 0; i < m; i ++){
			cin>>a>>b;
			g[a].push_back(b);
		}
		DFS(n);
		sort(p + 1, p + n + 1, cmp);

		for(int i = 1; i <= n; i ++){
			cout<<p[i].id;
			if(i != n) cout<<" ";
		}
		cout<<endl;
    }
    return 0;
}