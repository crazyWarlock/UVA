#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 110;
const int inf = 1000000;

int g[maxn][maxn]; //residual network
int color[maxn];
int pred[maxn];

void init(int n){
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			g[i][j] = 0;
		}
	}
}

int BFS(int s, int t, int n){
	queue<int> q;
	memset(color, 0, sizeof(color));
	memset(pred, 0, sizeof(pred));
	color[s] = 1;
	q.push(s);
	color[s] = 1;
	pred[s] = 0;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		color[tmp]=2;
		if(tmp == t) break;

		for(int i = 1; i <= n; i ++){
			if(g[tmp][i] > 0 && color[i] == 0){
				pred[i] = tmp;
				color[i] = 1;
				q.push(i);
			}
		}
	}

	int k = t;
	int augf = inf;
	while(pred[k] != 0){
		augf = min(augf, g[pred[k]][k]);
		k = pred[k];
	}

	return augf;
}

int EK(int s, int t, int n){
	int f;
	int ans = 0;
	while(f = BFS(s, t, n) != inf){
		int k = t;
		while(pred[k] != 0){
			g[pred[k]][k] -= f;
			g[k][pred[k]] += f;
			k = pred[k];
		}
		ans += f;
	}

	return ans;
}

int main(){
	int n, s, t, c, x, y, z;
	int id = 1;
	while (cin>>n)
	{
		if(n == 0) break;
		init(n);
		cin>>s>>t>>c;
		while(c --){
			cin>>x>>y>>z;
			g[x][y] += z;
			g[y][x] += z;
		}

		cout<<"Network "<<id++<<endl;
		cout<<"The bandwidth is "<<EK(s, t, n)<<"."<<endl<<endl;
	}
	return 0;
}
