#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main(){
	int T;
	string pro;
	map<char, double> m;
	map<char, char> d;
	m.insert(make_pair('U',-1));
	m.insert(make_pair('I',-1));
	m.insert(make_pair('P',-1));
	d.insert(make_pair('U', 'V'));
	d.insert(make_pair('I', 'A'));
	d.insert(make_pair('P', 'W'));

	cin>>T;
	cin.get();
	for(int t = 1; t <= T; t ++){
		getline(cin, pro);
		m['U'] = m['I'] = m['P'] = -1;

		for(int i = 0; i < pro.length(); i ++){
			if(pro[i]=='='){
				char x = pro[i-1];
				int j = i + 1;
				string val;
				double v;
				while(pro[j] != d[x]){
					if(pro[j] == 'm' || pro[j] =='k' || pro[j] == 'M'){
						j ++;
						break;
					}
					val.push_back(pro[j]);
					j ++;
				}
				v = atof(val.c_str());
				if(pro[j-1] == 'm') v /= 1000;
				if(pro[j-1] == 'k') v *= 1000;
				if(pro[j-1] == 'M') v *= 1000000;
				m[x] = v;
			}
		}
		cout<<"Problem #"<<t<<endl;
		if(m['U'] == -1)
			cout<<"U="<<fixed<<setprecision(2)<<m['P']/m['I']<<"V"<<endl<<endl;
		else if(m['I'] == -1)
			cout<<"I="<<fixed<<setprecision(2)<<m['P']/m['U']<<"A"<<endl<<endl;
		else
			cout<<"P="<<fixed<<setprecision(2)<<m['U']*m['I']<<"W"<<endl<<endl;
	}
	return 0;
}