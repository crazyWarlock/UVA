#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=200;
const int INF=1000000000;
int color[maxn][maxn];
int ans[maxn];
int va, vb, vc;

struct P{
	P(int aa, int bb, int cc, int p=0){a=aa;b=bb;c=cc;pour=p;}
	int a,b,c;
	int pour;
};

void BFS(int a, int b, int c){
	memset(color, 0, sizeof(color));
	for(int i = 0; i < maxn; i ++) ans[i]=INF;

	queue<P> q;
	q.push(P(a,b,c));
	color[a][b]=1;

	while(!q.empty()){
		P t = q.front();
		q.pop();
		color[t.a][t.b] = 2;
		ans[t.a]=min(ans[t.a], t.pour);
		ans[t.b]=min(ans[t.b], t.pour);
		ans[t.c]=min(ans[t.c], t.pour);

		if(t.a > 0){
			if(t.a + t.b <= vb && color[0][t.a+t.b]==0){
				q.push(P(0, t.a+t.b, t.c, t.pour+t.a));
				color[0][t.a+t.b]=1;
			}else if(t.a+t.b > vb && color[t.a+t.b-vb][vb]==0){
				q.push(P(t.a+t.b-vb, vb, t.c, t.pour+vb-t.b));
				color[t.a+t.b-vb][vb]=1;
			}

			if(t.a + t.c <= vc && color[0][t.b]==0){
				q.push(P(0, t.b, t.a+t.c, t.pour+t.a));
				color[0][t.b]=1;
			}else if(t.a + t.c > vc && color[t.a+t.c-vc][t.b]==0){
				q.push(P(t.a+t.c-vc, t.b, vc, t.pour + vc - t.c));
				color[t.a+t.c-vc][t.b]=1;
			}
		}
		if(t.b > 0){
			if(t.a + t.b <= va && color[t.a+t.b][0]==0){
				q.push(P(t.a+t.b, 0, t.c, t.pour+t.b));
				color[t.a+t.b][0]=1;
			}else if(t.a + t.c > va && color[va][t.a+t.b-va] == 0){
				q.push(P(va, t.a+t.b-va, t.c, t.pour+va-t.a));
				color[va][t.a+t.b-va] = 1;
			}

			if(t.b+t.c <= vc && color[t.a][0]==0){
				q.push(P(t.a, 0, t.b+t.c, t.pour+t.b));
				color[t.a][0]=1;
			}else if(t.b+t.c>vc && color[t.a][t.b+t.c-vc]==0){
				q.push(P(t.a,t.b+t.c-vc,vc,t.pour+vc-t.c));
				color[t.b][t.b+t.c-vc]=1;
			}
		}
		if(t.c > 0){
			if(t.a+t.c<=va && color[t.a+t.c][t.b]==0){
				q.push(P(t.a+t.c,t.b,0,t.pour+t.c));
				color[t.a+t.c][t.b]=1;
			}else if(t.a+t.c>va && color[va][t.b]==0){
				q.push(P(va, t.b, t.c+t.a-va, t.pour+va-t.a));
				color[va][t.b]=1;
			}

			if(t.b+t.c<=vb && color[t.a][t.b+t.c]==0){
				q.push(P(t.a,t.b+t.c,0,t.pour+t.c));
				color[t.a][t.b+t.c]=1;
			}else if(t.b+t.c>vb && color[t.a][vb]==0){
				q.push(P(t.a, vb, t.c+t.b-vb, t.pour+vb-t.b));
				color[t.a][vb]=1;
			}
		}
	}
}

int main(){
	int T;
	int d;
	cin>>T;

	while(T--){
		cin>>va>>vb>>vc>>d;
		BFS(0, 0, vc);
		for(int i = d; i >= 0; i --){
			if(ans[i] != INF){
				cout<<ans[i]<<" "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}