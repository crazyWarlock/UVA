#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn=1001;

int dp[maxn][maxn];

int main(){
	string s1, s2;
	
	while(getline(cin, s1) && getline(cin, s2)){
		memset(dp, 0, sizeof(dp));

		int m = s1.length();
		int n = s2.length();
		for(int i = 1; i <= m; i ++){
			for(int j = 1; j <= n; j ++){
				if(s1[i-1] == s2[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}

		cout<<dp[m][n]<<endl;
	}

	return 0;
}