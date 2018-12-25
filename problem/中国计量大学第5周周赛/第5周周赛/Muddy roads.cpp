#define LOCAL
#include<cstdio>
#include<algorithm>
using namespace std;
struct boards{
	int begin,end;
}board[50000];
bool cmp(const boards &a,const boards &b){
	if(a.begin==b.begin) return a.end>b.end;
	else return a.begin<b.begin;
}
int main(){
	int i,k,m,n,count;
	#ifdef LOCAL
	freopen("test.in_Muddy roads.txt","r",stdin);
	freopen("test.out_Muddy roads.txt","w",stdout);	
	#endif
	while(scanf("%d%d",&n,&m)!=EOF){
		count=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&board[i].begin,&board[i].end);
		}
		sort(board,board+n,cmp);
		for(i=0,k=board[0].begin;i<n;){
			if(k>=board[i].end){
				i++;
				if(i==n) break;
				if(k<board[i].begin) k=board[i].begin;
			}
			else{
				k=k+m;count++;
			}
		}
		printf("%d\n",count); 
	}
	return 0;
}
