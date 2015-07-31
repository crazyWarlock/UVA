#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef unsigned long long uLL;

uLL dp[1<<16];
uLL kill[1<<16];

int main()
{
	uLL T, N;
	uLL index;
	uLL des[18];
	char input[18];

	cin>>T;
	for(uLL t = 1; t<= T; t++){
		cin>>N;
		for(uLL i = 0; i <= N; i ++){
			cin>>input;
			index = 1;
			des[i] = 0;
			for(int j = 0; j < strlen(input); j ++){
				des[i] += (input[j] - '0') * index;
				index *= 2;
			}
		}

		memset(kill, 0, sizeof(kill));
		for(uLL i = 0; i < (1<<N); i ++){
			 kill[i] = kill[i] | des[0];
			 for(uLL j = 0; j < N; j ++){
				if((i & ((uLL)1<<j)) != 0){  //the jth has been killed
					kill[i] = kill[i] | des[j+1];
				}
			 }
		}

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		for(uLL i = 0; i < (1<<N); i ++){
			for(uLL j = 0; j < N; j ++){
				if(((i & ((uLL)1<<j)) != 0) && ((kill[i ^ (1<<j)] & ((uLL)1<<j)) != 0)){
					dp[i] += dp[i ^ (1<<j)];
				}
			}
		}

		cout<<"Case "<<t<<": "<<dp[(1<<N) - 1]<<endl;
	}
	return 0;
}