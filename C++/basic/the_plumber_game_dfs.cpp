//水管工游戏
#include<stdio.h>
int a[51][51];
int book[51][51],n,m,flag=0;
struct note {
	int x;
	int y;
}s[100];
int top = 0;
void dfs(int x,int y,int front){
	int i;
	if(x==n && y==m+1){
		flag=1;
		for(i=1;i<=top;i++){
			printf("(%d %d)",s[i].x,s[i].y);
		}
		return ;
	}
	if(x<1 || x>n || y<1 || y>m)
		return ;
	if(book[x][y]==1)
		return ;
	book[x][y] = 1;
	
	top++;
	s[top].x = x;
	s[top].y = y;
	//当前水管是直管的情况 
	if(a[x][y]>=5 && a[x][y]<=6){
		if(front==1){//进水管为左边 
			dfs(x,y+1,1);
		}
		if(front==2){//进水管为上边 
			dfs(x+1,y,2);
		}
		if(front==3){//进水管为右边 
			dfs(x,y-1,3);
		}
		if(front==4){//进水管为下边 
			dfs(x-1,y,4);
		}
	}
	
	//当前水管是弯的情况下
	if(a[x][y]>=1 && a[x][y]<=4){
		if(front==1){//进水管为左边 
			dfs(x+1,y,2);
			dfs(x-1,y,4);
		}
		if(front==2){//进水管为上边 
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
		if(front==3){//进水管为右边 
			dfs(x-1,y,4);
			dfs(x+1,y,2);
		}
		if(front==4){//进水管为下边 
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
	}
	book[x][y] = 0;
	top--;
	return ; 
}
int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
	dfs(1,1,1);
	
	if(flag==0)
		printf("impossible\n");
	else
		printf("找到铺设方案\n");
		
	getchar();getchar();
	return 0;
}
