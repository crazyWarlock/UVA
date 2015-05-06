#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int cnt=0;
	
	for(long long n = 3; cnt != 10; n ++){
		long long a = n*(n+1);
		long long b = a / 2;
		long long c = sqrt(b);
		if(c*c == b){
			cout.width(10);
			cout<<c;
			cout.width(10);
			cout<<n<<endl;
			cnt ++;
		}
	}

	return 0;
}