#define LOCAL 
#include<cstdio>
#include<iostream>
using namespace std;
int num[100001];
int main(){
	int i,m,n,flag;
	#ifdef LOCAL
	freopen("test.in_10-5.txt","r",stdin);
	freopen("test.out_10-5.txt","w",stdout);	
	#endif
	while(cin>>m){
		while(m--){
			flag=1;
			cin>>n;
			for(i=0;i<n;i++)
				cin>>num[i];
			for(i=0;i<n;i++){
				if(num[i]>=num[i+1])
					if(i==0||i==n-1) {flag=0;break;}
					else break;
			}
			for(;i<n-2;i++){
				if(num[i]<=num[i+1]) {flag=0;break;}
			}
			if(flag) printf("Yes\n");
			else printf("No\n");
			for(i=0;i<n;i++)
				num[i]=0;
		}
	}
	return 0;
}
