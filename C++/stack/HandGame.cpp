#include<stdio.h>
struct queue {
	int data[1000];
	int head;
	int tail;
};
struct stack{
	int data[10];
	int top;
};
int main(){
	struct queue q1,q2;
	struct stack s;
	int book[10];
	int i,t;
	
	q1.head=1;
	q1.tail=1;
	
	q2.head=1;
	q2.tail=1;
	
	s.top = 0;
	
	for (i=1;i<=9;i++)
		book[i] = 0;
		
	for (i=1;i<=6;i++){
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	for (i=1;i<=6;i++){
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}
	while(q1.head<q1.tail && q2.head<q2.tail){
		t = q1.data[q1.head];//q1出一张牌
		
		if(book[t]==0){//牌桌上没有q1出的这张牌 
			//q1此轮没有赢，就该去掉这张牌并把牌放进牌桌 
			q1.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		} else{//牌桌上有q1出的这个牌
			//q1此轮赢了,一次把牌桌的牌放入自己手中
			q1.head++;
			q1.data[q1.tail]=t;
			q1.tail++;
			while(s.data[s.top]!=t){
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			} 	
		}
		
		t = q2.data[q2.head];//q2出一张牌
		
		if(book[t]==0){//牌桌上没有q2出的这张牌 
			//q2此轮没有赢，就该去掉这张牌并把牌放进牌桌 
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		} else{//牌桌上有q2出的这个牌
			//q2此轮赢了,一次把牌桌的牌放入自己手中
			q2.head++;
			q2.data[q2.tail]=t;
			q2.tail++;
			while(s.data[s.top]!=t){
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			} 	
		}
	}
	
	if(q2.head==q2.tail){
		printf("小哼 Win\n");
		printf("小哼 当前手中的牌为:");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0){//说明桌面上有牌	
			printf("\n桌面上的牌是:");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
		}else
			printf("\n桌面上已经没有牌了");
	}else{
		printf("小哈 Win\n");
		printf("小哈 当前手中的牌为:");
		for(i=q1.head;i<=q2.tail-1;i++)
			printf(" %d",q2.data[i]);
		if(s.top>0){//说明桌面上有牌	
			printf("\n桌面上的牌是:");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
		}else
			printf("\n桌面上已经没有牌了");
	}
}
