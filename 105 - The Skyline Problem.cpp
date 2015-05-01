#include <iostream>
using namespace std;

int main(){
	int height[10001]={0};
	int l, h, r, left=10010, right=-10010;

	while(cin>>l>>h>>r){
		left = min(l, left);
		right = max(r, right);
		for(int i = l; i < r; i ++){
			if(h>height[i])
				height[i]=h;
		}
	}

	int curh = 0;
	for(int i = left; i < right; i ++){
		if(height[i]!=curh){
			cout<<i<<" "<<height[i]<<" ";
			curh = height[i];
		}
	}
	cout<<right<<" "<<0;
	cout<<endl;
	return 0;
}

/*
#include <iostream>
using namespace std;

#define LEFT(u) u<<1
#define RIGHT(u) ((u<<1)|1)

struct Building{
	int l, h, r;
}buildings[5010];

int segtree[10010*2]; // [)
int height[10010];

void build(int left, int right, int index){
	if(right > left + 1){
		int mid = (left + right) / 2;
		build(left, mid, LEFT(index));
		build(mid, right, RIGHT(index));
		segtree[index]=max(segtree[LEFT(index)], segtree[RIGHT(index)]);
	}else{
		segtree[index]=0;
	}
}

void update(int left, int right, int index, int tleft, int tright, int value){
	int mid = (left + right) / 2;
	if(left == tleft && right == tright){
		segtree[index] = max(value, segtree[index]);
	}else if(mid >= tright){
		update(left, mid, LEFT(index), tleft, tright, value);
	}else if(mid <= tleft){
		update(mid, right, RIGHT(index), tleft, tright, value);
	}else{
		update(left, mid, LEFT(index), tleft, mid, value);
		update(mid, right, RIGHT(index), mid, tright, value);
	}
}

int query(int left, int right, int index, int tleft, int tright){
	int mid = (left + right)/2;
	if(left == tleft && right == tright)
		return segtree[index];
	else if(mid >= tright){
		segtree[LEFT(index)] = max(segtree[index], segtree[LEFT(index)]);
		return query(left, mid, LEFT(index), tleft, tright);
	}else if(mid <= tleft){
		segtree[RIGHT(index)] = max(segtree[index], segtree[RIGHT(index)]);
		return query(mid, right, RIGHT(index), tleft, tright);
	}else{
		segtree[LEFT(index)] = max(segtree[index], segtree[LEFT(index)]);
		segtree[RIGHT(index)] = max(segtree[index], segtree[RIGHT(index)]);
		return max(query(left, mid, LEFT(index), tleft, mid), query(mid, right, RIGHT(index), mid, tright));
	}
}

int main(){
	int l, h, r;
	int left = 10010, right = 0;
	int cnt = 0;

	while(cin>>l>>h>>r){
		buildings[cnt].l = l;
		buildings[cnt].h = h;
		buildings[cnt++].r = r;
		left = min(l, left);
		right = max(r, right);
	}

	build(left, right + 1, 1);
	for(int i = 0; i < cnt; i ++){
		update(left, right + 1, 1, buildings[i].l, buildings[i].r, buildings[i].h);
	}

	for(int i = left; i <= right; i ++){
		height[i] = query(left, right + 1, 1, i, i + 1);
	}

	for(int i = left; i <= right;){
		int j = i + 1;
		cout<<i<<" "<<height[i];
		if(i == right) break;
		else cout<<" ";
		while(j <= right && height[j] == height[i]){
			j ++;
		}
		i = j;
	}
	cout<<endl;

	return 0;
}
*/