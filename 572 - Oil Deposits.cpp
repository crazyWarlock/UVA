#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=100;
char g[maxn][maxn];
int color[maxn][maxn];
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

struct P{
	P(int rr, int cc){r=rr; c=cc;}
	int r, c;
};

void BFS(int r, int c){
	queue<P> q;
	q.push(P(r,c));
	color[r][c]=1;

	while(!q.empty()){
		P t = q.front();
		color[t.r][t.c]=2;
		q.pop();
		for(int i = 0; i < 8; i ++){
			int rr = t.r + dir[i][0];
			int cc = t.c + dir[i][1];
			if(color[rr][cc]==0 && g[rr][cc]=='@'){
				q.push(P(rr,cc));
				color[rr][cc]=1;
			}
		}
	}
}

int main(){
	int m, n;
	while(cin>>m>>n){
		if(m == 0) break;
		
		for(int i = 0; i < m; i ++)
			for(int j = 0; j < n; j ++) cin>>g[i][j];

		int ans = 0;
		memset(color, 0, sizeof(color));
		for(int i = 0; i < m; i ++){
			for(int j = 0; j < n; j ++){
				if(color[i][j] == 0	&& g[i][j] == '@'){
					BFS(i,j);
					ans ++;
				}
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
