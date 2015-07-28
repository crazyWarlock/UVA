#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 0x7fffffff;

int main()
{
	int t, n, w;

	cin>>t;

	while(t--){
		cin>>n>>w;
		vector<int> vec(n + 1, 0);
		vector<double> sum(n + 1, 0);
		vector<double> dvec(n, 0);
		vector<vector<double>> dp(n+1, vector<double>(w+1, INF));

		int s = 0;
		for(int i = 1; i <= n; i ++){
			cin>>vec[i];
			s += vec[i];
		}

		for(int i = 1; i <= n; i ++){
			dvec[i - 1] = vec[i] * 1.0 / s;
		}

		sort(dvec.begin(), dvec.end());
		reverse(dvec.begin(), dvec.end());

		sum[1] = dvec[0];

		for(int i = 2; i <= n; i ++){
			sum[i] = sum[i-1] + dvec[i-1];
		}

		for(int i = 1; i <= n; i ++){
			dp[i][1] = sum[i] * i;
		}

		for(int i = 1; i <= n; i ++){
			for(int j = 2; j <= min(i, w); j ++){
				for(int k = 1; k < i; k ++){
					dp[i][j] = min(dp[i][j], dp[k][j-1] + i * 1.0 * (sum[i] - sum[k]));
				}
			}
		}

		cout<<fixed<<setprecision(4)<<dp[n][w]<<endl;
	}
	return 0;
}