#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=52;
const int INF=1000000000;
int cut[maxn];
int dp[maxn][maxn];

int main(){
	int l, n;

	while(cin>>l){
		if(l == 0) break;

		cin>>n;
		
		for(int i = 0; i < n; i ++)
			cin>>cut[i];
		cut[n]=0;
		cut[n+1]=l;
		sort(cut, cut+n+2);

		for(int i = 0; i < n + 2; i ++){
			dp[i][i+1]=dp[i][i]=0;
			for(int j = i + 2; j < n + 2; j ++){
				dp[i][j] = INF;
			}
		}

		for(int len = 2; len <= n + 1; len ++){
			for(int i = 0; i < n + 2; i ++){
				int j = i + len;
				if(j >= n + 2) break;
				for(int k = i + 1; k < j; k ++){
					dp[i][j] = min(dp[i][k]+dp[k][j] + (cut[j] - cut[i]), dp[i][j]);
				}
			}
		}

		cout<<"The minimum cutting is "<<dp[0][n+1]<<"."<<endl;
	}
	return 0;
}
