#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector< vector<int> >& bk){
	for(int i = 0; i < bk.size(); i ++){
		cout<<i<<":";

/*		while(!bk[i].empty()){
			cout<<" "<<bk[i].front();
			bk[i].erase(bk[i].begin());
		}
*/	
		for(int j = 0; j < bk[i].size(); j ++){
			cout<<" "<<bk[i][j];
		}
		cout<<endl;
	}
}

void moveonto(vector< vector<int> >& bk, vector<int>& p, int a, int b){
	int pa = p[a];
	int pb = p[b];

	while(bk[pa].back() != a){
		int bac = bk[pa].back();
		p[bac]=bac;
		bk[bac].push_back(bac);
		bk[pa].pop_back();
	}
	while(bk[pb].back() != b){
		int bac = bk[pb].back();
		p[bac]=bac;
		bk[bac].push_back(bac);
		bk[pb].pop_back();
	}
	p[a]=pb;
	bk[pb].push_back(a);
	bk[pa].pop_back();
}

void moveover(vector< vector<int> >& bk, vector<int>& p, int a, int b){
	int pa = p[a];
	int pb = p[b];

	while(bk[pa].back() != a){
		int bac = bk[pa].back();
		p[bac]=bac;
		bk[bac].push_back(bac);
		bk[pa].pop_back();
	}
	p[a]=pb;
	bk[pb].push_back(a);
	bk[pa].pop_back();
}

void pileonto(vector< vector<int> >& bk, vector<int>& p, int a, int b){
	int pa = p[a];
	int pb = p[b];

	while(bk[pb].back() != b){
		int bac = bk[pb].back();
		p[bac]=bac;
		bk[bac].push_back(bac);
		bk[pb].pop_back();
	} 

	vector<int> tmp;
	while(bk[pa].back() != a){
		int bac = bk[pa].back();
		p[bac]=pb;
		tmp.push_back(bac);
		bk[pa].pop_back();
	} 

	p[a]=pb;
	bk[pb].push_back(a);
	bk[pa].pop_back();

	for(int i = tmp.size() - 1; i >= 0; i --){
		bk[pb].push_back(tmp[i]);
	}
}

void pileover(vector< vector<int> >& bk, vector<int>& p, int a, int b){
 	int pa = p[a];
	int pb = p[b];

	vector<int> tmp;
	while(bk[pa].back() != a){
		int bac = bk[pa].back();
		p[bac]=pb;
		tmp.push_back(bac);
		bk[pa].pop_back();
	} 

	p[a]=pb;
	bk[pb].push_back(a);
	bk[pa].pop_back();
	for(int i = tmp.size() - 1; i >= 0; i --){
		bk[pb].push_back(tmp[i]);
	}
}

int main()
{
	int n;
	string cd;
	cin>>n;
	
	vector< vector<int> > blocks;
	vector<int> pos;
	for(int i = 0; i < n; i ++){
		vector<int> tmp;
		tmp.push_back(i);
		blocks.push_back(tmp);
		pos.push_back(i);
	}

	string act, prep;
	int from, to;

	while(cin>>cd){
		if(cd == "quit") break;

		act = cd;
		cin>>from>>prep>>to;
		if(from == to || pos[from]==pos[to]) continue;
		if(act == "move"){
			if(prep == "onto"){
				moveonto(blocks, pos, from, to);
			}else{
				moveover(blocks, pos, from, to);
			}
		}else{
			if(prep == "onto"){
				pileonto(blocks, pos, from, to);
			}else{
				pileover(blocks, pos, from, to);
			}
		}
	}
	print(blocks);
	return 0;
}