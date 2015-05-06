#include <iostream>
#include <queue>
using namespace std;

const int maxn=21;
const int INF=100;
int g[maxn][maxn];


void floyd(int n){
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}

int main()
{
	int n, N, id=1;
	while(cin>>n){
		for(int i = 1; i <= 20; i ++){
			g[i][i]=0;
			for(int j = i + 1; j <= 20; j ++){
				g[i][j]=g[j][i]=INF;
			}
		}

		int x;
		for(int i = 0; i < n; i ++){
			cin>>x;
			g[1][x] = 1;
			g[x][1] = 1;
		}
		for(int i = 2; i <= 19; i ++){
			cin>>n;
			for(int j = 0; j < n; j ++){
				cin>>x;
				g[i][x] = g[x][i] = 1;
			}
		}

		floyd(20);
		cin>>N;
		int a, b;
		cout<<"Test Set #"<<id++<<endl;
		for(int i = 0; i < N; i ++){
			cin>>a>>b;
			cout.width(2);
			cout<<std::right<<a;
			cout<<" to ";
			cout.width(2);
			cout<<std::right<<b;
			cout.width(2);
			cout<<std::left<<":";
			cout<<g[a][b]<<endl;
		}
		cout<<endl;
	}

	return 0;
}