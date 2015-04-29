#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int k, n;
int boxes[31][10];
int rela[31][31];//0 =; 1 >; -1 <
int res[31];

int cmp(int lhs, int rhs){
	int larr[10];
	int rarr[10];
	for(int i = 0; i < n; i ++){
		larr[i]=boxes[lhs][i];
		rarr[i]=boxes[rhs][i];
	}

	sort(larr, larr + n);
	sort(rarr, rarr + n);

	for(int i = 0; i < n; i ++){
		if(larr[i]>=rarr[i])
			return 0;
	}
	return 1;
}

int dp(int s){
	if(res[s] != 0) return res[s];

	res[s]=1;
	for(int i = 1; i <= k; i ++){
		if(rela[s][i] == 1){
			res[s] = max(res[s], dp(i) + 1);
		}
	}
	return res[s];
}

void print(int id){
	cout<<id;
	for(int i = 1; i <= k; i ++){
		if(res[i] == res[id] - 1 && rela[id][i]){
			cout<<" ";
			print(i);
			break;
		}
	}
}

int main(){
	while(cin>>k>>n){
		for(int i = 1; i <= k; i ++)
			for(int j = 0; j < n; j ++)
				cin>>boxes[i][j];

		for(int i = 1; i <= k; i ++){
			for(int j = 1; j <= k; j ++){
				rela[i][j]=cmp(i,j);
			}
		}

		memset(res, 0, sizeof(res));
		for(int i = 1; i <= k; i ++)
			dp(i);

		int mlen = 0, id;
		for(int i = 1; i <= k; i ++){
			if(res[i]>mlen){
				mlen = res[i];
				id = i;
			}
		}
		cout<<mlen<<endl;
		print(id);
		cout<<endl;
	}
	return 0;
}