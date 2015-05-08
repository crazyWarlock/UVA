#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;

const int maxn=100;
const double INF=1000000000;

double g[maxn][maxn];
double dis[maxn];

struct P{
	double x, y;
}ps[maxn];

double prim(int src, int n){
	memset(dis, 0, sizeof(dis));

	for(int i = 0; i < n; i ++) dis[i]=g[src][i];

	int minone = -1;
	double mindis;
	double ans = 0;
	for(int i = 0; i < n - 1; i ++){
		mindis=INF;
		for(int j = 0; j < n; j ++){
			if(dis[j]<mindis && dis[j]!=0){
				minone=j;
				mindis=dis[j];
			}
		}
		dis[minone]=0;
		ans += mindis;
		for(int j = 0; j < n; j ++)
			if(dis[j] > g[j][minone])
				dis[j] = g[j][minone];
	}
	return ans;
}

int main(){
	int T, n;

	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; i ++){
			cin>>ps[i].x>>ps[i].y;
		}

		for(int i = 0; i < n; i ++){
			g[i][i]=0;
			for(int j = i + 1; j < n; j ++){
				g[j][i]=g[i][j]=sqrt((ps[i].x-ps[j].x)*(ps[i].x-ps[j].x)+(ps[i].y-ps[j].y)*(ps[i].y-ps[j].y));
			}
		}

		cout<<fixed<<setprecision(2)<<prim(0, n)<<endl;
		if(T) cout<<endl;
	}
	return 0;
}