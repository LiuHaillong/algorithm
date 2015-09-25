//最少转机--图的广度优先遍历
#include<stdio.h>
struct note{
	int x;//城市编号 
	int s;//转机次数 
}; 
int main(){
	struct note que[2501];
	int head,tail,cur;	
	int i,j,n,m,a,b,start,end,book[51]={0},e[51][51]={0},flag=0;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=99999999;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;
	}
	
	head=1;
	tail=1;
	que[tail].x=start;
	que[tail].s=0;
	tail++;
	book[1]=start;
	
	
	while(head<tail){
		cur = que[head].x;
		for(i=1;i<=n;i++){
			if(e[cur][i]!=99999999 && book[i]==0){
				que[tail].x=i;
				que[tail].s=que[head].s+1;
				tail++;
				book[i]=1;
			}
			
			if(que[tail].x==end){
				flag=1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	 	head++;
	}
	
	
	printf("\n");
	printf("%d",que[tail-1].s);
	
	getchar();getchar();
	return 0;
}
