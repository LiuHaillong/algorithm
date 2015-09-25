//用dfs(深搜)去探索岛屿 
// 0 表示海洋 1-9表示陆地
// 计算将落地所在岛屿的面积(即有多少个格子) 
#include<stdio.h>
int a[50][51]={
 {1,2,1,0,0,0,0,0,2,3}
,{3,0,2,0,1,2,1,0,1,2}
,{4,0,1,0,1,2,3,2,0,1}
,{3,2,0,0,0,1,2,4,0,0}
,{0,0,0,0,0,0,1,5,3,0}
,{0,1,2,1,0,1,5,4,3,0}
,{0,1,2,3,1,3,6,2,1,0}
,{0,0,3,4,8,9,7,5,0,0}
,{0,0,0,3,7,8,6,0,1,2}
,{0,0,0,0,0,0,0,0,1,0}},book[50][50];
int n=9,m=9, sum;
void dfs(int x,int y){
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右 下 左 上 
	
	int k,tx,ty;
	for(k=0;k<=3;k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		
		if(tx<0 || tx>n || ty<0 || ty>m)
			continue;
		if(a[tx][ty]!=0 && book[tx][ty]==0){
			sum++;
			book[tx][ty] = 1;
			dfs(tx,ty);
//			book[tx][ty] = 0;
		}
	}
	return ;
}
int main(){
	int i,j,startx,starty;
//	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	scanf("%d %d",&startx,&starty);
//	for(i=0;i<n;i++)
//		for(j=0;j<m;j++)
//			scanf("%d",&a[i][j]);

	book[startx][starty] = 1;	
	sum=1;
	dfs(startx,starty);
	
	printf("%d\n",sum);
	
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%d",book[i][j]);
		}
		printf("\n");
	}
	
	getchar();getchar();
	return 0;
}
