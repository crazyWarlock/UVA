#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn=21;
const int prime=199;
string dic[maxn];
string sen[maxn];

int head[prime];
int _next[maxn];

int keys[maxn];

void init(){
	memset(head, -1, sizeof(head));
	memset(_next, -1, sizeof(_next));
	memset(keys, 0, sizeof(keys));
}

void insert(int id){
	int key = 0;
	for(int i = 0; i < dic[id].size(); i ++){
		key += ((dic[id][i] - 'a') * (dic[id][i] - 'a')) % maxn;
		key %= maxn;
	} 
	_next[id]=head[key];
	head[key] = id;
}

int find(string str){
	int key = 0;
	for(int i = 0; i < str.size(); i ++){
		key += ((str[i] - 'a') * (str[i] - 'a')) % maxn;
		key %= maxn;
	} 

	for(int j = head[key]; j != -1; j = _next[j]){
		if(str == dic[j]) return 1;
	}
	return -1;
}
int main(){
	int K, E, t = 1;

	while(cin>>K>>E){
		init();
		for(int i = 0; i < K; i ++){
			cin>>dic[i];
			insert(i);
		}

		int maxk = -1;
		cin.get();
		for(int i = 0; i < E; i ++){
			getline(cin, sen[i]);
		
			int len = sen[i].length();
			string str;
			str.clear();
			for(int j = 0; j < len; j ++){
				if(sen[i][j] >= 'a' && sen[i][j] <= 'z'){
					str.push_back(sen[i][j]);
				}else if(sen[i][j] >= 'A' && sen[i][j] <= 'Z'){
					str.push_back(tolower(sen[i][j]));
				}else{
					if(!str.empty()){
						if(find(str) == 1){
							keys[i] ++;
						}
					}
					str.clear();
				}
			}
			maxk = max(maxk, keys[i]);
		}
		cout<<"Excuse Set #"<<t++<<endl;
		for(int i = 0; i < E; i ++){
			if(keys[i]==maxk) cout<<sen[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}