//�����������(BFS) !!!
#include<stdio.h>
struct note{
	int x;//x���� 
	int y;//y���� 
	int f;//�����ڶ����еı�ţ����ⲻ��Ҫ���·�������Բ���Ҫf 
	int s;//���� 
};
int main(){
	struct note que[2501];//��Ϊ��ͼ��С���ᳬ��50*50�������չ���в��ᳬ��2500
	int a[51][51]={0},book[51][51]={0};//a �� �ڽӾ���洢ͼ book������ʺ�ļ�¼ͼ 1 ��ʾ�Ѿ����� 0��ʾδ����
	
	//����һ�����߷��������
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//�� �� �� �� 
	
	int head,tail;
	int n,m,i,j,k,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//���г�ʼ��
	head = 1;
	tail = 1;
	
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;//��������Ƿ񵽴�Ŀ��㣬0��ʾ��ʱ��û�е��� 1��ʾ����
	while(head<tail){
		//ö��4������
		for(k=0;k<4;k++){
			tx = que[head].x + next[k][0];//������һ���� tx
			ty = que[head].y + next[k][1];//������һ���� ty
			
			//�ж��Ƿ�Խ��
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			
			//û���ϰ��� �� ��δ�߹� 
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
