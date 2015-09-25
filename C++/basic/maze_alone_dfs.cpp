// 0 表示海洋 1-9表示陆地
// 计算有多少独立的岛屿 
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
void dfs(int x,int y,int color){
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右 下 左 上 
	
	int k,tx,ty;
	a[x][y]=color;
	for(k=0;k<=3;k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		
		if(tx<0 || tx>n || ty<0 || ty>m)
			continue;
		if(a[tx][ty]!=0 && book[tx][ty]==0){
			sum++;
			book[tx][ty] = 1;
			dfs(tx,ty,color);
//			book[tx][ty] = 0;
		}
	}
	return ;
}
int main(){
	int i,j,startx,starty;
//	scanf("%d %d",&n,&m);
//	for(i=0;i<n;i++)
//		for(j=0;j<m;j++)
//			scanf("%d",&a[i][j]);

	int num=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(a[i][j]>0){
				num--;
				book[i][j]=1;
				dfs(i,j,num);
			}
		}		
	}
	

	
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	
	printf("%d\n",-num);
	getchar();getchar();
	return 0;
}
