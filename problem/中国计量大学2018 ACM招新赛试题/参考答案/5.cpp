#include <cstdio>
int n[4];
char c[10005];
int main()
{
	int i;
	while(scanf("%s",c)!=EOF){
		for(i=0;c[i]!='\0';i++){
			if(c[i]==67||c[i]==99) n[0]++;
			if(c[i]==74||c[i]==106) n[1]++;
			if(c[i]==76||c[i]==108) n[2]++;
			if(c[i]==85||c[i]==117) n[3]++;
		}
		for(;n[0]!=0||n[1]!=0||n[2]!=0||n[3]!=0;){
			if(n[0]!=0) {printf("C");n[0]--;}
			if(n[1]!=0) {printf("J");n[1]--;}
			if(n[2]!=0) {printf("L");n[2]--;}
			if(n[3]!=0) {printf("U");n[3]--;}
		}
		printf("\n");
	}
	return 0;
}
