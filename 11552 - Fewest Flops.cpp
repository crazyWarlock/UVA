#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;

int main()
{
	int t, k;
	string str;

	cin>>t;
	while(t --){
		cin>>k;
		cin>>str;
		
		int len = str.length();
		int m = len / k;

		vector<vector<int>> dp(m + 1, vector<int>(k+1, INF));
		vector<vector<bool>> v(m + 1, vector<bool>(26, false));
		vector<int> cnt(m + 1, 0);
		
		int q = 0;
		for(int i = 0; i < len; i += k){
			q ++;
			for(int j = i; j < i + k; j ++){
				char ch = str[j];
				if(!v[q][ch - 'a']) cnt[q] ++;

				v[q][ch-'a'] = true;
			}
		}

		for(int i = 1; i <= k; i ++) dp[1][i] = cnt[1];

		for(int i = 2; i <= m; i ++){
			for(int j = 1; j <= k; j ++){
				for(int p = 1; p <= k; p ++){
					char a = str[(i - 2) * k + p - 1];
					char b = str[(i - 1) * k + j - 1];

					if(v[i][a-'a'] && (b != a || cnt[i] == 1))
						dp[i][j] = min(dp[i][j], dp[i-1][p] + cnt[i] - 1);
					else
						dp[i][j] = min(dp[i][j], dp[i-1][p] + cnt[i]);
				}
			}
		}																								   

		int res = INF;
		for(int i = 1; i <= k; i ++)
			res = min(res, dp[m][i]);
		cout<<res<<endl;
	}

	return 0;
}