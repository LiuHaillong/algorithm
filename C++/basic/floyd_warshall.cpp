//floyd-Warshall算法，多源最短路径
#include<stdio.h>
int main(){
	int e[10][10],i,j,k,n,m,a,b,c;
	int inf=99999999;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=inf;
	
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;
	}
	
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
				
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%10d",e[i][j]);
		}
		printf("\n");
	}
	
	
	getchar();getchar();
	return 0;
} 
