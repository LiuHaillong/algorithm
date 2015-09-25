//用BFS求解一个点使得消灭的人数最多 
#include<stdio.h>
struct note{
	int x;//横坐标 
	int y;//纵坐标 
};
char a[20][21]={
 {"#############"}
,{"#GG.GGG#GGG.#"}
,{"###.#G#G#G#G#"}
,{"#.......#..G#"}
,{"#G#.###.#G#G#"}
,{"#GG.GGG.#.GG#"}
,{"#G#.#G#.#.#.#"}
,{"##G...G.....#"}
,{"#G#.#G###.#G#"}
,{"#...G#GGG.GG#"}
,{"#G#.#G#G#.#G#"}
,{"#GG.GGG#G.GG#"}
,{"#############"}};//用来存储地图 

int getnum(int i,int j){
	int sum,x,y;
	sum = 0;
	//向上统计可以消灭的敌人 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		x--;
	}
	
	//向下统计可以消灭的敌人 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		x++;
	}
	
	//向左统计可以消灭的敌人 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		y--;
	}
	
	//向右统计可以消灭的敌人 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		y++;
	}
	return sum;
}

int main(){
	struct note que[401];//地图最大为20*20，因此队列长度不会超过400
	int book[20][20]={0};// book表示走过记录访问图
	int head,tail;
	int i,j,k,n=13,m=13,startx,starty,tx,ty;
	int sum,max=0,mx,my;
	
	//定义一个行走方向的数组
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右 下 左 上 
	
//	scanf("%d %d %d %d",&n,&m,&startx,&starty);
//	for(i=0;i<=n-1;i++)
//			scanf("%s",&a[i]);
	
	scanf("%d %d",&startx,&starty);
			
	//队列初始化
	head = 1;
	tail = 1; 
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	
	max = getnum(startx,starty);
	mx = startx;
	my = starty;

	while(head<tail){
		for(k=0;k<=3;k++){
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			
			if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
				continue;
			//当前点不是墙壁 而且为走过 
			if(a[tx][ty]=='.' && book[tx][ty]==0){
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
				
				sum = getnum(tx,ty);
				if(sum > max){
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		head++;
	}
	printf("将炸弹放置在(%d,%d)处,可以消灭%d个敌人\n",mx,my,max);
	getchar();getchar();
	return 0;
}
