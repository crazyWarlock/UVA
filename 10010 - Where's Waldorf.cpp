#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 51;
char maze[maxn][maxn];
char pat[maxn];
int m, n, k;

bool match(int r, int c, int len){
	int rib = c + len - 1;
	int lob = r + len - 1;
	int leb = c - len + 1;
	int upb = r - len + 1;

	int i;
	if(rib <= n){
		for(i = 0; i < len; i ++)
			if(maze[r][c+i] != pat[i]) break;
		if(i == len) return true;

		if(lob <= m){
			for(i = 0; i < len; i ++)
				if(maze[r+i][c+i] != pat[i]) break;
			if(i == len) return true;
		}
	}
	if(lob <= m){
		for(i = 0; i < len; i ++)
			if(maze[r+i][c] != pat[i]) break;
		if(i == len) return true;

		if(leb >= 1){
			for(i = 0; i < len; i ++)
				if(maze[r+i][c-i] != pat[i]) break;
			if(i == len) return true;
		}
	}

	if(leb >= 1){
		for(i = 0; i < len; i ++)
			if(maze[r][c-i] != pat[i]) break;
		if(i == len) return true;

		if(upb >= 1){
			for(i = 0; i < len; i ++)
				if(maze[r-i][c-i] != pat[i]) break;
			if(i == len) return true;
		}
	}

	if(upb>=1){
		for(i = 0; i < len; i ++)
			if(maze[r-i][c] != pat[i]) break;
		if(i == len) return true;

		if(rib <= n){
			for(i = 0; i < len; i ++)
				if(maze[r-i][c+i] != pat[i]) break;
			if(i == len) return true;
		}
	}

	return false;
}

int main(){
	int T;

	cin>>T;
	for(int u = 0; u < T; u ++){
		if(u != 0) cout<<endl;

		cin>>m>>n;
		for(int i = 1; i <= m; i ++){
			for(int j = 1; j <= n; j ++){
				cin>>maze[i][j];
				maze[i][j]=tolower(maze[i][j]);
			}
		}

		cin>>k;
		
		for(int t = 1; t <= k; t ++){
			cin>>pat;
			int len = strlen(pat);
			for(int x = 0; x < len; x++)
				pat[x]=tolower(pat[x]);

			int f=0;
			for(int i = 1; i <= m; i ++){
				for(int j = 1; j <= n; j ++){
					if(match(i,j,len)){
						cout<<i<<" "<<j<<endl;
						f = 1;
						break;
					}
				}
				if(f==1) break;
			}
		}
	}
	return 0;
}
