#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


const int maxn = 27;
list<int> g[maxn];
int color[maxn];
int _time;
int used[maxn];
struct P{
	int id, fin;
}p[maxn];

bool cmp(const P& lhs, const P& rhs){
	return lhs.fin > rhs.fin;
}

void DFS_Visit(int src){
	_time++;
	list<int>::iterator it;
	for (it = g[src].begin(); it != g[src].end(); it++){
		if (color[*it] == 0){
			color[*it] = 1;
			DFS_Visit(*it);
		}
	}
	color[src] = 2;
	_time++;
	p[src].fin = _time;
}

void DFS(int n){
	memset(color, 0, sizeof(color));
	_time = 0;

	for (int i = 1; i <= n; i++){
		if (used[i] == 0){
			p[i].id = i;
			p[i].fin = -1;
			continue;
		}
		p[i].id = i;
		if (color[i] == 0){
			color[i] = 1;
			DFS_Visit(i);
		}
	}
}

void init(){
	for (int i = 0; i < maxn; i++){
		g[i].clear();
	}
}
int main()
{
	string a, b;
	init();

	cin >> a;
	while (cin >> b){
		if (b == "#") break;
		int minlen = a.length() < b.length() ? a.length() : b.length();

		for (int i = 0; i < minlen; i++){
			if (a[i] != b[i]){
				used[a[i] - 'A' + 1] = used[b[i] - 'A' + 1] = 1;
				g[a[i] - 'A' + 1].push_back(b[i] - 'A' + 1);
				break;
			}
		}
		a = b;
	}

	DFS(26);

	sort(p + 1, p + 27, cmp);

	for (int i = 1; i <= 26; i++){
		if (p[i].fin != -1){
			cout <<(char)(p[i].id + 'A' - 1);
		}
	}
	cout << endl;
	return 0;
}

/*
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 30;

int g[maxn][maxn];
map<char, int> m;
vector<int> res;
char dic[maxn];
int deg[maxn];
int vis[maxn];

void DFS(int src, int len){
	for (int j = 0; j < len; j++){
		if (g[src][j] == 1) deg[j]--;
	}

	for (int i = 0; i < len; i++){
		if (vis[i] == 0 && deg[i] == 0){
			vis[i] = 1;
			res.push_back(i);
			DFS(i, len);
		}
	}
}

void init(){
	for (int i = 0; i < maxn; i++){
		for (int j = 0; j < maxn; j++){
			g[i][j] = 0;
		}
	}
	memset(deg, 0, sizeof(deg));
	memset(vis, 0, sizeof(vis));
	res.clear();
	m.clear();
}

int main(){
	int len = 0;
	string a, b;

	init();
	cin >> a;

	while (cin >> b){
		if (b == "#") break;
		
		int minlen = b.length() < a.length() ? b.length() : a.length();
		
		int i;
		for (i = 0; i < minlen; i++){
			if (a[i] != b[i]){
				if (m.find(a[i]) == m.end()){
					m.insert(make_pair(a[i], len));
					dic[len++] = a[i];
				}

				if (m.find(b[i]) == m.end()){
					m.insert(make_pair(b[i], len));
					dic[len++] = b[i];
				}
				g[m[a[i]]][m[b[i]]] = 1;
				deg[m[b[i]]] ++;
				break;
			}
		}
		a = b;
	}

	for (int j = 0; j < len; j++){
		if (deg[j] == 0 && vis[j] == 0){
			res.push_back(j);
			vis[j] = 1;
			DFS(j, len);
		}
	}

	for (int j = 0; j < len; j++){
		cout << dic[res[j]];
	}
	cout << endl;
	return 0;
}*/

