#include <iostream>
using namespace std;

const int maxn=21;
int cor[maxn];
int ans[maxn];
int dp[maxn][maxn];

int LCS(int n){
	for(int i = 0; i <= n; i ++){
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(cor[i] == ans[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][n];
}

int main(){
	int n;
	cin>>n;

	int a;
	for(int i = 1; i <= n; i ++){
		cin>>a;
		cor[a]=i;
//		cin>>cor[i];
	}

	while(cin>>a){
		ans[a]=1;
		for(int i = 2; i <= n; i ++){
			cin>>a;
			ans[a]=i;
//			cin>>ans[i];
		}
		cout<<LCS(n)<<endl;
	}
}