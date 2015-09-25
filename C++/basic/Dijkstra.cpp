//Dijkstra(��һ���㵽�������������·��)---��Դ���·��
#include<stdio.h>
int main(){
	int n,m,i,j,u,v,min,book[101]={0},e[101][101]={0},t1,t2,t3,dis[101]={0};
	int inf = 99999999;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=inf;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	}
		
	//��1������������·�� 
	for(i=1;i<=n;i++){
		dis[i]=e[1][i];
	} 
	book[1]=1;
	
	
	//Dijkstra���� 
	for(i=1;i<=n-1;i++){
		//�ҵ���1�Ŷ�������Ķ��� 
		min = inf;
		for(j=1;j<=n;j++){
			if(book[j]==0 && dis[j]<min){
				min = dis[j];
				u = j;
			}
		}
		book[u]=1;
		for(v=1;v<=n;v++){
			if(e[u][v]<inf){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v];
				}
			}
		}
	} 
	
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
		
	getchar();getchar();
	return 0;
} 
