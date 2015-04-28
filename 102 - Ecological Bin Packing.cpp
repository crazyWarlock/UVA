#include <iostream>
using namespace std;

int bottle[3][3];

int BCG(int sum){
	return sum - bottle[0][0] - bottle[1][2] - bottle[2][1];
}

int BGC(int sum){
	return sum - bottle[0][0] - bottle[1][1] - bottle[2][2];
}

int CBG(int sum){
	return sum - bottle[0][2] - bottle[1][0] - bottle[2][1];
}

int CGB(int sum){
	return sum - bottle[0][2] - bottle[1][1] - bottle[2][0];
}

int GBC(int sum){
	return sum - bottle[0][1] - bottle[1][0] - bottle[2][2];
}

int GCB(int sum){
	return sum - bottle[0][1] - bottle[1][2] - bottle[2][0];
}

int main()
{
	while(cin>>bottle[0][0]>>bottle[0][1]>>bottle[0][2]>>bottle[1][0]>>bottle[1][1]>>bottle[1][2]>>bottle[2][0]>>bottle[2][1]>>bottle[2][2]){
	
		int sum = 0;
		for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 3; j ++){
				sum += bottle[i][j];
			}
		}

	int res = BCG(sum);
	int k = 1;

	int tmp = BGC(sum);
	if(tmp < res){
		res = tmp;
		k = 2;
	}
	tmp = CBG(sum);
	if(tmp < res){
		res = tmp;
		k = 3;
	}
	tmp = CGB(sum);
	if(tmp<res){
		res = tmp;
		k = 4;
	}
	tmp=GBC(sum);
	if(tmp<res){
		res = tmp;
		k = 5;
	}
	tmp=GCB(sum);
	if(tmp<res){
		res=tmp;
		k = 6;
	}

	switch(k){
	case 1:
		cout<<"BCG ";
		break;
	case 2:
		cout<<"BGC ";
		break;
	case 3:
		cout<<"CBG ";
		break;
	case 4:
		cout<<"CGB ";
		break;
	case 5:
		cout<<"GBC ";
		break;
	case 6:
		cout<<"GCB ";
		break;
	}
	cout<<res<<endl;
	}
	return 0;
}