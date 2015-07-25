#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;

list<int> g[maxn];
int arr[maxn * 2];
int dp[maxn * 2][maxn];

int main()
{
	int T, n1, n2, a, b, n;
	cin >> T;
	while (T--){
		for (int i = 0; i < maxn; i++) g[i].clear();

		cin >> n1 >> n2;
		while (n2--){
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n1; j++){
				dp[i][j] = 0x7fffffff;
			}
		}

		for (int i = 1; i <= n1; i++){
			dp[0][n] = 0;
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n1; j++){
				dp[i][j] = min(dp[i-1][j] + (j == arr[i] ? 0 : 1), dp[i][j]);
				
				for (auto k : g[j]){
					dp[i][j] = min(dp[i-1][k] + (j == arr[i] ? 0 : 1), dp[i][j]);
				}
			}
		}

		int res = 0x7fffffff;
		for (int i = 1; i <= n1; i++){
			res = min(dp[n][i], res);
		}
		cout << res << endl;
	}

	return 0;
}