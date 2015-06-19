#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 55;
const int maxm = 550;
const int inf = 1000000000;

int gf[ maxn ][ maxn ];
int a[ maxn ];
int p[maxn];
int from[maxm];
int to[maxm];

void maxflow(int n){
	queue<int> q;
	
	while(1){
		memset(a, 0, sizeof(a));
		a[1] = inf;
		q.push(1);

		while(!q.empty()){
			int tmp = q.front();
			q.pop();

			for(int i = 1; i <= n; i ++){
				if(gf[tmp][i] > 0 && a[i] == 0){
					p[i] = tmp;
					a[i] = min(a[tmp], gf[tmp][i]);
					q.push(i);
				}
			}
		}

		if(a[2] == 0) break;
		int k = 2;
		while(k != 1){
			gf[p[k]][k] -= a[2];
			gf[k][p[k]] += a[2];
			k = p[k];
		}
	}
}


int main(){
	int m, n, x, y, z;

	while(scanf("%d %d", &n, &m) != EOF){
		if(m == 0 && n == 0) break;

		memset(gf, 0, sizeof(gf));

		for(int i = 0; i < m; i ++){
			//cin>>x>>y>>z;
			scanf("%d %d %d", &x,&y,&z);
			gf[x][y] = z;
			gf[y][x] = z;
			from[i] = x;
			to[i] = y;
		}

		maxflow(n);

		for(int i = 0; i < m; i ++){
			if((a[from[i]] && !a[to[i]]) || (a[to[i]] && !a[from[i]]))
					printf("%d %d\n", from[i], to[i]);
		}
		printf("\n");
	}
	return 0;
}