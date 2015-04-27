#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000010;

long long res[maxn];

int main()
{
	 int i, j;
	 
	 memset(res, 0, sizeof(res));
	 res[1] = 1;
	 res[2] = 2;

	 for(long long p = 3; p < maxn; p ++){
		long long q = p;
		long long cnt = 0;
		 while(1){
			if(q>=maxn){
				cnt ++;
				if(q%2 == 0) q/=2;
				else q=3*q+1;
				continue;
			}

			if(res[q]!=0){
				res[p]=res[q]+cnt;
				break;
			}else{
				if(q%2==0) q/=2;
				else q=q*3+1;
			}
			cnt ++;
		}
		if(res[q]<=0)cout<<res[q]<<endl;
	 }
	 while(cin>>i>>j){
		
		long long ans=0;
		int a = min(i,j);
		int b = max(i,j);
		for(int k = a; k <= b; k ++){
			if(res[k]>ans)
				ans=res[k];
		}

		cout<<i<<" "<<j<<" "<<ans<<endl;
	 }

	 return 0;
}