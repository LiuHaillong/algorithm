//��DFS���һ����ʹ�������������� 
#include<stdio.h>
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
,{"#############"}};
int book[20][20],max,mx,my,n=13,m=13;
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

void dfs(int x,int y){
	//����һ�����߷��������
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//�� �� �� �� 
	int k,sum,tx,ty;
	sum = getnum(x,y);
	if(sum>max){
		max = sum;
		mx = x;
		my = y;
	}
	
	for(k=0;k<=3;k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		
		if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
			continue;
		if(a[tx][ty]=='.' && book[tx][ty]==0){
			book[tx][ty] = 1;
			dfs(tx,ty);
			book[tx][ty] = 0;
		}
	}
	return ;
}

int main(){
	int i,j,k,startx,starty;
	
//	scanf("%d %d %d %d",&n,&m,&startx,&starty);
//	
//	for(i=0;i<=n-1;i++)
//		scanf("%s",a[i]);

	scanf("%d %d",&startx,&starty);
		
	book[startx][starty] = 1;
	max = getnum(startx,starty);
	mx = startx;
	my = starty;
	
	dfs(startx,starty);
	
	printf("��ը��������(%d,%d)��,��������%d������\n",mx,my,max);
	getchar();getchar();
	return 0;
}
