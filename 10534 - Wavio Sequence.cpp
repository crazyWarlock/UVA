#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int stack[maxn];

int main(){
	int N;
	
	while (cin >> N){
		vector<int> vec(N, 0);
		for (int i = 0; i < N; i++){
			cin >> vec[i];
		}

		vector<int> llis(N, 1);
		vector<int> rlis(N, 1);

		int len = 1;
		stack[len++] = vec[0];
		llis[0] = 1;

		for (int i = 1; i < N; i++){
			if (vec[i] > stack[len-1]){
				llis[i] = len;
				stack[len++] = vec[i];
			}
			else{
				int left = 1, right = len - 1;
				while (left <= right){
					int mid = (left + right) >> 1;
					if (vec[i] > stack[mid]) left = mid + 1;
					else right = mid - 1;
				}

				stack[left] = vec[i];
				llis[i] = left;
			}
		}

		reverse(vec.begin(), vec.end());

		len = 1;
		stack[len++] = vec[0];
		rlis[0] = 1;
		for (int i = 1; i < N; i++){
			if (vec[i] > stack[len-1]){
				rlis[i] = len;
				stack[len++] = vec[i];
			}
			else{
				int left = 1, right = len;
				while (left <= right){
					int mid = (left + right) >> 1;
					if (vec[i] > stack[mid]) left = mid + 1;
					else right = mid - 1;
				}

				stack[left] = vec[i];
				rlis[i] = left;
			}
		}
		int res = 0;
		for (int i = 0; i < N; i++){
			res = max(res, min(llis[i], rlis[N - 1 - i]));
		}
		cout << 2 * res - 1 << endl;
	}

	return 0;
}