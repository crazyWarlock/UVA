#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int maxn = 1010;
int dp[maxn];
string str;

bool check(int left, int right){
	while (left < right && str[left] == str[right]){
		left++;
		right--;
	}

	return left >= right;
}

int main()
{
	int x;

	cin >> x;
	while (x--){
		cin >> str;
		int n = str.length();

		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++){
			dp[i] = dp[i-1] + 1;
			for (int j = 1; j < i; j++){
				if (check(j - 1, i - 1)){
					dp[i] = min(dp[i], dp[j-1] + 1);
				}
			}
		}

		cout << dp[n] << endl;
	}

	return 0;
}