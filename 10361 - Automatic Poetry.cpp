#include<iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string l1, l2;
	cin>>n;
	cin.get();
	while(n--){
		getline(cin, l1);
		getline(cin, l2);

		int cnt = 1;
		string s1, s2, s3, s4, s5;
		for(int i = 0; i < l1.length(); i ++){
			if(l1[i]=='<')
				cnt++;
			else if(l1[i]=='>')
				cnt++;
			else{
				if(cnt==2){
					s2.push_back(l1[i]);
				}else if(cnt==3){
					s3.push_back(l1[i]);
				}else if(cnt==4){
					s4.push_back(l1[i]);
				}else if(cnt==5){
					s5.push_back(l1[i]);
				}else{
					s1.push_back(l1[i]);
				}
				cout<<l1[i];
			}
		}
		cout<<endl;

		for(int i = 0; i < l2.length(); i ++){
			if(l2[i] == '.') break;
			else cout<<l2[i];
		}
		cout<<s4<<s3<<s2<<s5<<endl;
	}
	return 0;
}