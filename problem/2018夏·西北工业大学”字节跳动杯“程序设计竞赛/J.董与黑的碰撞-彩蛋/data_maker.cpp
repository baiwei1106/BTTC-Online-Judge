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

int t, n, x, y;
P G[3];

bool judge(){
	return (G[0] - G[1]).det(G[0] - G[2]) != 0;
}

int main(){
	freopen("in.txt", "w", stdout);
	srand((unsigned int)time(NULL));

	t = rand() % 1000 + 1;
	printf("%d\n", t);

	for(int i = 0; i < t; i++){
		while(true){
			for(int j = 0; j < 3; j++){
				G[j].x = rand() % 2000 - 1000;
				G[j].y = rand() % 2000 - 1000;
			}
			if(judge()) break;
		}

		for(int j = 0; j < 3; j++){
			printf("%d %d\n", G[j].x, G[j].y);
		}

		n = rand() % 1000 + 1;
		printf("%d\n", n);

		for(int j = 0; j < n; j++){
			x = rand() % 2000 - 1000;
			y = rand() % 2000 - 1000;
			printf("%d %d\n", x, y);
		}

		printf("\n");
	}

	return 0;
}
