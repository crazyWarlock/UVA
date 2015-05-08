/*
#include <iostream>
#include <cstring>
using namespace std;

const int maxn=7490;
int coins[5]={1, 5, 10, 25, 50};
int dp[maxn];

int main(){
	int cents;

	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	for(int i = 0; i < 5; i ++){
		for(int j = 1; j < maxn; j ++){
			if(j >= coins[i]){
				dp[j] += dp[j-coins[i]];
			}
		}
	}
	while(cin>>cents)
		cout<<dp[cents]<<endl;
	return 0;
}
 */

#include <iostream>
#include <cstring>
using namespace std;

const int maxn=7490;
long long res[maxn][5];
int coins[5]={1, 5, 10, 25, 50};

long long dp(int s, int c){
	if(res[s][c] != -1) return res[s][c];

	res[s][c]=0;

	for(int i = c; i < 5; i ++){
		if(s >= coins[i]){
			res[s][c] += dp(s-coins[i], i);
		}
	}
	return res[s][c];
}
int main(){
	int cents;
	
	for(int i = 0; i < maxn; i ++){
		for(int j = 0; j < 5; j ++){
			res[i][j]=-1;
		}
	}
	for(int i = 0; i < 5; i ++){
		res[0][i]=1;
	}

	while(cin>>cents){
		cout<<dp(cents, 0)<<endl;
	}
	return 0;
}