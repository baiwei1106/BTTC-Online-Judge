#define LOCAL
#include<cstdio>
#include<algorithm>
using namespace std;
struct concerts{
	long long begin,end;
}concert[20],happy[20];
bool cmp(const concerts &a,const concerts &b){
	if(a.begin==b.begin) return a.end<b.end;
	else return a.begin<b.begin;
}
long long k,m,n,res;
int cnt;
void dfs(long long pos,int i,long long ans,long long number){
	if(number>m) return;
	if(i>=cnt+1||number==m){
		if(ans>res) res=ans;
		return;
	}
	long long len,num,position,p1,p2;
	if(pos<happy[i].end){
		if(happy[i].end-happy[i].begin+1>happy[i].end-pos)
			len=happy[i].end-pos;
		else len=happy[i].end-happy[i].begin+1;
		p1=len%k;
		if(p1==0) p2=len/k;
		else p2=len/k+1;
		if(p2+number>m){
			if(res<ans+(m-number)*k) res=ans+(m-number)*k;
		}
		if(happy[i].begin+p2*k-1>pos+p2*k) position=happy[i].begin+p2*k-1;
		else position=pos+p2*k;
		num=p2*k;
		dfs(position,i+1,ans+num,number+p2);//不选最后一个点
        dfs(happy[i].end+k-1,i+1,ans+num+happy[i].end+k-1-position,number+p2+1);//选择最后一个点
    }
    else if(pos>=happy[i].end){
        dfs(pos,i+1,ans,number);//不选最后一个点
        dfs(happy[i].end+k-1,i+1,ans+happy[i].end+k-1-pos,number+1);//选择最后一个点
    }
}
int main(){
	int i,j,t;
	#ifdef LOCAL
	freopen("test.in_Kpop Music Party.txt","r",stdin);
	freopen("test.out_Kpop Music Party.txt","w",stdout);	
	#endif
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%lld%lld%lld",&n,&k,&m);
			for(i=0;i<n;i++)
				scanf("%lld%lld",&concert[i].begin,&concert[i].end);
			sort(concert,concert+n,cmp);
			cnt=0;
			for(i=0;i<n;){
				for(j=i;j<n;j++){
					if(concert[j].begin<=concert[i].end+1){
						if(concert[j].end>concert[i].end) 
							concert[i].end=concert[j].end;
					}
					else break;
				}
				happy[++cnt]=concert[i];i=j;
			}
			res=0;
			dfs(0,1,0,0);
			printf("%lld\n",res);
		}
	}
	return 0;
}
