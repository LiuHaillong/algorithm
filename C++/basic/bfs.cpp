//宽度优先搜索(BFS) !!!
#include<stdio.h>
struct note{
	int x;//x坐标 
	int y;//y坐标 
	int f;//父亲在队列中的编号，本题不需要输出路径，可以不需要f 
	int s;//步数 
};
int main(){
	struct note que[2501];//因为地图大小不会超过50*50，因此扩展队列不会超过2500
	int a[51][51]={0},book[51][51]={0};//a 是 邻接矩阵存储图 book代表访问后的记录图 1 表示已经访问 0表示未访问
	
	//定义一个行走方向的数组
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右 下 左 上 
	
	int head,tail;
	int n,m,i,j,k,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//队列初始化
	head = 1;
	tail = 1;
	
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;//用来标记是否到达目标点，0表示暂时还没有到达 1表示到达
	while(head<tail){
		//枚举4个方向
		for(k=0;k<4;k++){
			tx = que[head].x + next[k][0];//计算下一个点 tx
			ty = que[head].y + next[k][1];//计算下一个点 ty
			
			//判断是否越界
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			
			//没有障碍物 且 尚未走过 
			if(a[tx][ty]==0 && book[tx][ty]==0){
				book[tx][ty] = 1;
				que[tail].x  = tx;
				que[tail].y  = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			
			if(tx==p && ty==q){
				flag = 1;
				break;
			} 
		}
		if(flag==1)
			break;
		head++; 
	} 
	printf("%d",que[tail-1].s);
	getchar();getchar();
	return 0;
}
