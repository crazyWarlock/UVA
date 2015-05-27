#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 20;
int g[maxn][maxn];
map < char, int > m;
char dic[maxn];
int deg[maxn];
int color[maxn];
int _index;
vector<string> res;

void init(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			g[i][j] = 0;
		}
		deg[i] = 0;
	}
}

void DFS(int src, string str){
	if (str.length() == _index){
		res.push_back(str);
		return;
	}
	for (int j = 0; j < _index; j++){
		if (g[src][j] == 1){
			deg[j] --;
		}
	}

	for (int j = 0; j < _index; j++){
		if (color[j] == 0 && deg[j] == 0){
			string a = str;
			a.push_back(dic[j]);
			color[j] = 1;
			DFS(j, a);
			color[j] = 0;
		}
	}

	for (int j = 0; j < _index; j++){
		if (g[src][j] == 1){
			deg[j] ++;
		}
	}
}

int main(){
	int T;
	string str;
	cin >> T;
	cin.get();
	while (T--){
		cin.get();
		getline(cin, str);
		istringstream iss(str);
		_index = 0;
		while(iss){
			string sub;
			iss >> sub;
			if (sub == "\0") break;
			m.insert(make_pair(sub[0], _index));
			dic[_index] = sub[0];
			_index++;
		}
		init(_index);

		getline(cin, str);
		
		istringstream iss1(str);
		while(iss1){
			string sub;
			iss1 >> sub;
			if (sub == "") break;
			g[m[sub[0]]][m[sub[2]]] = 1;
			deg[m[sub[2]]]++;
		}

		res.clear();
		for (int i = 0; i < _index; i++){
			if (deg[i] == 0){
				memset(color, 0, sizeof(color));
				string tmp;
				tmp.push_back(dic[i]);
				color[i] = 1;
				DFS(i, tmp);
			}
		}

		if (res.size() == 0){
			cout << "NO" << endl;
			continue;
		}
		sort(res.begin(), res.end());

		for (int i = 0; i < res.size(); i++){
			for (int j = 0; j < res[i].length(); j++){
				if (j != 0) cout << " ";
				cout << res[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}