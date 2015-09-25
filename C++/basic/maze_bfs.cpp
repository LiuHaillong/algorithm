//用bfs(宽搜)去探索岛屿 
// 0 表示海洋 1-9表示陆地
// 计算将落地所在岛屿的面积(即有多少个格子) 
#include<stdio.h>
struct node{
	int x;
	int y;
};
int a[50][51];
int book[50][50],head,tail,n,m,sum,max;
int main(){
	int i,j,k,startx,starty,tx,ty;
	scanf ("%d %d %d %d",&n,&m,&startx,&starty);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	
	struct node que[2501];
	head = 1;
	tail = 1;
	book[startx][starty]=1;
	que[tail].x =  startx;
	que[tail].y =  starty;
	tail++;
	
	sum=1;
	max=1;
	while(head<tail){
		int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右 下 左 上 
		for(k=0;k<=3;k++){
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			
			if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
				continue;
			if(a[tx][ty]!=0 && book[tx][ty]==0){
				sum++;
				book[tx][ty]=1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;
	}
	
	printf("%d\n",sum);
	getchar();getchar();
	return 0;
}
