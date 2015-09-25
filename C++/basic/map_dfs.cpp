//图的深度优先遍历
#include<stdio.h>
int n,m,sum=0,book[101],e[101][101];//n为顶点数 m为几条边 
void dfs(int cur){
	int i;
	printf("%d ",cur);
	sum++;
	if(sum==n)
		return ;
	for(i=1;i<=n;i++){
		if(e[cur][i]==1 && book[i]==0){
			book[i]=1;
			dfs(i);
		}
	}
	return ;
} 
int main(){
	int i,j,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i==j)
				e[i][j]==0;
			else
				e[i][j]=99999999;
		}
	}
	
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;
	}
	book[1]=1;
	dfs(1);
	
	getchar();getchar();
	return 0;
}
