#define LOCAL
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int> gas;
struct stations{
	int dist,fuel;
}station[50000];
bool cmp(const stations &a,const stations &b){
	if(a.dist==b.dist) return a.fuel>b.fuel;
	else return a.dist>b.dist;
}
int main(){
	int i,k,l,n,p,count,flag,now;
	#ifdef LOCAL
	freopen("test.in_Expedition.txt","r",stdin);
	freopen("test.out_Expedition.txt","w",stdout);	
	#endif
	while(scanf("%d",&n)!=EOF){
		flag=0;count=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&station[i].dist,&station[i].fuel);
		scanf("%d%d",&l,&p);
		sort(station,station+n,cmp);
		now=0;
		while(p<l){
			for(i=now;i<n;i++){
				if(l-p>station[i].dist){
					now=i;break;
				}
				else gas.push(station[i].fuel);
			}
			l=l-p;p=0;
			if(gas.empty()&&l>0){
				flag=1;break;
			}
			p=p+gas.top();
			gas.pop();
			count++;
		}
		if(flag) printf("-1\n");
		else printf("%d\n",count);
	}
	return 0;
}
