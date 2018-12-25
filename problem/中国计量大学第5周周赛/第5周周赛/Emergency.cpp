#define LOCAL
#include<cstdio>
#define inf 1000000000
int map[505][505],team[505],dist[505],vertex[505],amount[505],count[505];
int m,n,begin,end;
void Dijkstra(int s){
	amount[s]=team[s];
	dist[s]=0;
	count[s]=1;
	while(1){
		int i,next,distmin=inf;
		for(i=0;i<n;i++){
			if(vertex[i]==0&&dist[i]<distmin){
				distmin=dist[i];
				next=i;
			}	
		}
		if(distmin==inf||next==end) break;
		vertex[next]=1;
		for(i=0;i<n;i++){
			if(dist[i]>dist[next]+map[next][i]){
				dist[i]=dist[next]+map[next][i];
				amount[i]=amount[next]+team[i];
				count[i]=count[next];
			}
			else if(dist[i]==dist[next]+map[next][i]){
				count[i]=count[i]+count[next];
				if(amount[i]<amount[next]+team[i])
					amount[i]=amount[next]+team[i];
			}
		}
	}
}
int main(){
	int i,j,node1,node2,distance;
	#ifdef LOCAL
	freopen("test.in_Emergency.txt","r",stdin);
	freopen("test.out_Emergency.txt","w",stdout);	
	#endif
	while(scanf("%d%d%d%d",&n,&m,&begin,&end)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&team[i]);
		for(i=0;i<n;i++){
			dist[i]=inf;
			for(j=0;j<n;j++)
				map[i][j]=inf;	
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&node1,&node2,&distance);
			map[node1][node2]=map[node2][node1]=distance;
		}
		Dijkstra(begin);
		printf("%d %d\n",count[end],amount[end]);
	}
	return 0;
}
