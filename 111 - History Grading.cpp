#include <iostream>
using namespace std;

const int maxn = 21;

int gr[maxn][maxn];
int g[maxn][maxn];
int cor[maxn];
int ans[maxn];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i ++) cin>>cor[i];

	for(int i = 1; i <= n; i ++)
		for(int j = i+1; j <= n; j ++){
			gr[i][j] = -1;
			gr[j][i] = 1;
		}

	while(cin>>ans[0]){
		for(int i = 1; i < n; i ++)
			cin>>ans[i];

		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++){
				if(gr[i][j] == -1)
					g[i][j] = 1;
				else
					g[i][j] = 0;
				g[j][i]=0;
			}


	}
	return 0;
}