//��BFS���һ����ʹ�������������� 
#include<stdio.h>
struct note{
	int x;//������ 
	int y;//������ 
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
,{"#############"}};//�����洢��ͼ 

int getnum(int i,int j){
	int sum,x,y;
	sum = 0;
	//����ͳ�ƿ�������ĵ��� 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		x--;
	}
	
	//����ͳ�ƿ�������ĵ��� 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		x++;
	}
	
	//����ͳ�ƿ�������ĵ��� 
	x = i;
	y = j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')
			sum++;
		y--;
	}
	
	//����ͳ�ƿ�������ĵ��� 
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
	struct note que[401];//��ͼ���Ϊ20*20����˶��г��Ȳ��ᳬ��400
	int book[20][20]={0};// book��ʾ�߹���¼����ͼ
	int head,tail;
	int i,j,k,n=13,m=13,startx,starty,tx,ty;
	int sum,max=0,mx,my;
	
	//����һ�����߷��������
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//�� �� �� �� 
	
//	scanf("%d %d %d %d",&n,&m,&startx,&starty);
//	for(i=0;i<=n-1;i++)
//			scanf("%s",&a[i]);
	
	scanf("%d %d",&startx,&starty);
			
	//���г�ʼ��
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
			//��ǰ�㲻��ǽ�� ����Ϊ�߹� 
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
	printf("��ը��������(%d,%d)��,��������%d������\n",mx,my,max);
	getchar();getchar();
	return 0;
}
