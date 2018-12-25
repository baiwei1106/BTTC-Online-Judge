#include<bits/stdc++.h>

using namespace std;

struct P{
	int x, y;
	P(){}
	P(int x, int y): x(x), y(y){}
	P operator -(P a){
		return P(x - a.x, y - a.y);
	}
	int det(P a){
		return x * a.y - y * a.x;
	}
};

int T, n;
P G[3], A;

int abs(int x){
	if(x >= 0) return x;
	return -x;
}

int area(P a, P b, P c){
	return abs((b - a).det(c - a));
}

bool judge(P a, P b, P c){
	return (b - a).det(c - a) != 0;
}

bool solve(P k){
	int a = area(G[0], G[1], G[2]);
	int b = area(k, G[0], G[1]) + area(k, G[1], G[2]) + area(k, G[0], G[2]);
	return a == b && judge(k, G[0], G[1]) && judge(k, G[0], G[2]) && judge(k, G[1], G[2]);
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);

	while(T--){
		for(int i = 0; i < 3; i++){
			scanf("%d %d", &G[i].x, &G[i].y);
		}

		scanf("%d", &n);
		int res = 0;
		for(int i = 0; i < n; i++){
			scanf("%d %d", &A.x, &A.y);
			if(solve(A)) res++;
		}

		printf("%d\n", res);
	}

	return 0;
}
