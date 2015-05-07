#include <iostream>
using namespace std;

const int PRIME=9949;
const int maxn=500010;

int head[PRIME];
int Next[maxn];

struct Exc{
	int f, t;
}exc[maxn];

void insert(int id){
	int h = (exc[id].f * exc[id].f) % PRIME;
	Next[id] = head[h];
	head[h]=id;
}

bool find(int f, int t){
	int h = (t*t) % PRIME;
	for(int i = head[h]; i != -1; i = Next[i]){
		if(exc[i].f == t && exc[i].t == f) return true;
	}
	return false;
}

void Delete(int f, int t){
	int h = (f*f) % PRIME;
	if(exc[head[h]].f == f && exc[head[h]].t == t){
		head[h] = Next[head[h]];
		return;
	}

	for(int i = head[h], j = -1; i != -1; j = i, i = Next[i]){
		if(exc[i].f == f && exc[i].t == t){
			Next[j] = Next[i];
			return;
		}
	}
}

int main(){
	int n;

	while(cin>>n){
		if(n == 0) break;

		for(int i = 0; i < PRIME; i ++){
			head[i] = -1;
		}
		for(int i = 0; i < maxn; i ++){
			Next[i] = -1;
		}

		for(int i = 0; i < n; i ++){
			cin>>exc[i].f>>exc[i].t;
			if(!find(exc[i].f, exc[i].t)){
				insert(i);
			}else{
				Delete(exc[i].t, exc[i].f);
			}
		}

		int f = 0;
		for(int i = 0; i < PRIME; i ++){
			if(head[i] != -1){
				f = 1;
				break;
			}
		}
		if(f) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

	return 0;
}