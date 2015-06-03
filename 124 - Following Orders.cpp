#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 25;
map<char, int> m;
char aset[ maxn ];
int g[maxn][maxn];
int deg[maxn];
int vis[maxn];
vector<string> res;

void DFS(int src, int n, string str){
	if(str.length() == n){
		res.push_back(str);
		return;
	}

	for(int i = 0; i < n; i ++){
		if(g[src][i] == 1){
			deg[i] --;
		}
	}

	for(int i = 0; i < n; i ++){
		if(deg[i] == 0 && vis[i] == 0){
			string t = str;
			vis[i]=1;
			t.push_back(aset[i]);
			DFS(i, n, t);
			vis[i]=0;
		}
	}

	for(int i = 0; i < n; i ++){
		if(g[src][i] == 1){
			deg[i] ++;
		}
	}
}

void init(int l){
	for(int i = 0; i < l ; i ++){
		for(int j = 0; j < l; j ++){
			g[i][j]=0;
		}
		deg[i] = 0;
	}
	res.clear();
}

int main(){
	string alphabet, cons;
	int cnt = 0;
	while(getline(cin, alphabet)){
		if(cnt != 0) cout<<endl;
		else cnt = 1;

		int len = 0;

		m.clear();
		for(int i = 0; i < alphabet.length(); i ++){
			if(islower(alphabet[i])){
				m.insert(make_pair(alphabet[i], len));
				aset[len++] = alphabet[i];
			}
		}
		
		init(len);
		char a = ' ';

		getline(cin, cons);
		for(int i = 0; i < cons.length(); i ++){
			if(islower(cons[i])){
				if(a == ' '){
					a = cons[i];
				}else{
					g[m[a]][m[cons[i]]] = 1;
					deg[m[cons[i]]]++;
					a = ' ';
				}
			}
		}

		for(int i = 0; i < len; i ++){
			memset(vis, 0, sizeof(vis));
			if(deg[i] == 0){
				vis[i]=1;
				string t;
				t.push_back(aset[i]);
				DFS(i, len, t);
			}
		}

		sort(res.begin(), res.end());

		for(int i = 0; i < res.size(); i ++){
			cout<<res[i]<<endl;
		}
	}
	return 0;
}