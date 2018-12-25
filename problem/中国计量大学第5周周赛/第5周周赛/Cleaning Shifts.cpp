#define LOCAL
#include<cstdio>
#include<algorithm>
using namespace std;
struct shifts{
	int begin,end;
}shift[50000];
bool cmp(const shifts &a,const shifts &b){
	if(a.begin==b.begin) return a.end>b.end;
	else return a.begin<b.begin;
}
int main(){
	int i,k,l,m,n,count,flag,flag1,flag2;
	#ifdef LOCAL
	freopen("test.in_Cleaning Shifts.txt","r",stdin);
	freopen("test.out_Cleaning Shifts.txt","w",stdout);	
	#endif
	while(scanf("%d%d",&n,&m)!=EOF){
		flag1=flag2=1;
		for(i=0;i<n;i++){
			scanf("%d%d",&shift[i].begin,&shift[i].end);
			if(shift[i].begin==1) flag1=0;
			if(shift[i].end==m) flag2=0;
		}
		sort(shift,shift+n,cmp);
		if(flag1||flag2) printf("-1\n");
		else{
			flag=0;
			for(i=1,k=shift[0].end,l=0,count=1;k<m;i++){
				if(shift[i].begin<=k+1){
					if(shift[i].end>l) l=shift[i].end;
				}
				else{
					if(l==0){
						flag=1;break;
					}
					else{
						k=l;l=0;count++;i--;
					}
				}
			}
			if(flag) printf("-1\n");
			else printf("%d\n",count);
		}
	}
	return 0;
} 
